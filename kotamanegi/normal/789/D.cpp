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
#include<map>
#include <iomanip>
#include <time.h>
#include <random>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define LONG_INF 10000000000000000
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
vector<long long> vertexs[2000000];
long long required[2000000] = {};
long long visited[2000000] = {};
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	long long n, m;
	cin >> n >> m;
	if (m == 1) {
		cout << 0 << endl;
		return 0;
	}
	long long final_counter = 0;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		if (a != b) {
			vertexs[a].push_back(b);
			vertexs[b].push_back(a);
		}
		else {
			final_counter++;
		}
		required[a] = true;
		required[b] = true;
	}
	long long wowowow = final_counter * (final_counter - 1);
	wowowow /= 2;
	long long ans = final_counter * (m - final_counter);
	ans += wowowow;
	for (int i = 1;i <= n;++i) {
		if (required[i] == true) {
			queue<int> nexter;
			nexter.push(i);
			visited[i] = true;
			while (nexter.empty() == false) {
				long long hoge = nexter.front();
				nexter.pop();
				for (int q = 0;q < vertexs[hoge].size();++q) {
					if (visited[vertexs[hoge][q]] == false) {
						visited[vertexs[hoge][q]] = true;
						nexter.push(vertexs[hoge][q]);
					}
				}
				long long nya = (long long)vertexs[hoge].size();
				long long te = (long long)((long long)vertexs[hoge].size() - (long long)1);
				nya *= te;
				nya /= (long long)2;
				ans += nya;
			}
			goto ok;
		}
	}
ok:;
	for (int i = 1;i <= n;++i) {
		if (visited[i] != required[i]) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}