#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
const int aa = 201, bb = 201, cc = 500;
tuple<int,int,int> back[aa][bb][cc];
void output_solution(tuple<int, int, int> now) {
	if (now == make_tuple(0, 0, 0)) {
		return;
	}
	tuple<int, int, int> next = back[get<0>(now)][get<1>(now)][get<2>(now)];
	output_solution(back[get<0>(now)][get<1>(now)][get<2>(now)]);
	if (get<2>(now) > get<2>(next)) {
		cout << "(";
	}
	else {
		cout << ")";
	}
	return;
}
int main(){
	string s, t;
	cin >> s >> t;
	REP(i, aa) {
		REP(q, bb) {
			REP(t, cc) {
				back[i][q][t] = make_tuple(-1, -1, -1);
			}
		}
	}
	back[0][0][0] = make_tuple(0, 0, 0);
	queue<tuple<int, int, int>> next;
	next.push(make_tuple(0, 0, 0));
	while (next.empty() == false) {
		tuple<int, int, int> now = next.front();
		next.pop();
		if (get<0>(now) == s.length() && get<1>(now) == t.length()&&get<2>(now) == 0) {
			output_solution(now);
			cout << endl;
			return 0;
		}
		REP(q, 2) {
			char next_bracket = '(';
			if (q == 1) {
				next_bracket = ')';
			}
			int next_x = get<0>(now);
			int next_y = get<1>(now);
			int next_z = get<2>(now);
			if (q == 0) {
				next_z++;
			}
			else {
				next_z--;
			}
			if (next_x < s.length()) {
				if (s[next_x] == next_bracket) {
					next_x++;
				}
			}
			if (next_y < t.length()) {
				if (t[next_y] == next_bracket) {
					next_y++;
				}
			}
			if (next_z >= 0&&next_z < 500) {
				if (back[next_x][next_y][next_z] == make_tuple(-1, -1, -1)) {
					back[next_x][next_y][next_z] = now;
					next.push(make_tuple(next_x, next_y, next_z));
				}
			}
		}
	}
}