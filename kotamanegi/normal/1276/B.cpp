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
#define int long long
vector<int> vertexs[300000];
int bad[300000];
int union_tree[300000];
long long cnt[300000];
int ok[300000];
int union_find(int now) {
	if (union_tree[now] == now) return now;
	return union_tree[now] = union_find(union_tree[now]);
}
int union_merge(int a, int b) {
	a = union_find(a);
	b = union_find(b);
	union_tree[a] = b;
	return 0;
}
#undef int
int main(){
#define int long long
	int test_case;
	cin >> test_case;
	REP(i,test_case){
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		REP(i, n) {
			vertexs[i].clear();
			union_tree[i] = i;
			cnt[i] = 0;
			ok[i] = 0;
			bad[i] = 0;
		}
		a--; b--;
		REP(i, m) {
			int c, d;
			cin >> c >> d;
			c--; d--;
			vertexs[c].push_back(d);
			vertexs[d].push_back(c);
		}
		bad[a] = 1;
		bad[b] = 1;
		REP(i, n) {
			if (bad[i]) continue;
			REP(q, vertexs[i].size()) {
				int next = vertexs[i][q];
				if (bad[next]) continue;
				union_merge(i, next);
			}
		}
		REP(i, n) {
			cnt[union_find(i)]++;
		}
		REP(i, vertexs[a].size()) {
			ok[union_find(vertexs[a][i])] |= 1;
		}
		REP(i, vertexs[b].size()) {
			ok[union_find(vertexs[b][i])] |= 2;
		}
		ok[union_find(a)] = 3;
		ok[union_find(b)] = 3;
		long long cnter[2] = {};
		REP(i, vertexs[a].size()) {
			if (ok[union_find(vertexs[a][i])] != 3) {
				cnter[0] += cnt[union_find(vertexs[a][i])];
				ok[union_find(vertexs[a][i])] = 3;
			}
		}
		REP(i, vertexs[b].size()) {
			if (ok[union_find(vertexs[b][i])] != 3) {
				cnter[1] += cnt[union_find(vertexs[b][i])];
				ok[union_find(vertexs[b][i])] = 3;
			}
		}
		cout << cnter[0] * cnter[1] << endl;
	}
}