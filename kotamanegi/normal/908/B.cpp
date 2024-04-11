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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 2000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> mapping;
	for (int i = 0;i < n;++i) {
		string s;
		cin >> s;
		mapping.push_back(s);
	}
	string s;
	cin >> s;
	vector<int> moving = vector<int>({ 0,1,2,3 });
	int ans = 0;
	do {
		int x, y;
		for (int i = 0;i < n;++i) {
			for (int q = 0;q < m;++q) {
				if (mapping[i][q] == 'S') {
					x = i;
					y = q;
				}
			}
		}
		for (int i = 0;i < s.length();++i) {
			if (s[i] - '0' == moving[0]) {
				x++;
				if (x == -1 || x == n || mapping[x][y] == '#') {
					goto ok;
				}
				if (mapping[x][y] == 'E') {
					ans++;
					goto ok;
				}
			}
			if (s[i] - '0' == moving[1]) {
				x--;
				if (x == -1 || x == n || mapping[x][y] == '#') {
					goto ok;
				}
				if (mapping[x][y] == 'E') {
					ans++;
					goto ok;
				}
			}
			if (s[i] - '0' == moving[2]) {
				y++;
				if (y == -1 || y == m || mapping[x][y] == '#') {
					goto ok;
				}
				if (mapping[x][y] == 'E') {
					ans++;
					goto ok;
				}
			}
			if (s[i] - '0' == moving[3]) {
				y--;
				if (y == -1 || y == m || mapping[x][y] == '#') {
					goto ok;
				}
				if (mapping[x][y] == 'E') {
					ans++;
					goto ok;
				}
			}
		}
	ok:;
	} while (next_permutation(moving.begin(), moving.end()));
	cout << ans << endl;
	return 0;
}