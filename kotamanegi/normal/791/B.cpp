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
vector<int> vertexs[200000];
int visited[200000] = {};
int len[200000] = {};
int main() {
	iostream::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		vertexs[a].push_back(b);
		vertexs[b].push_back(a);
	}
	int cnt = 1;
	for (int i = 0;i < n;++i) {
		if (visited[i] == false) {
			visited[i] = cnt;
			len[cnt]++;
			queue<int> nexter;
			nexter.push(i);
			while (nexter.empty() == false) {
				int hoge = nexter.front();
				nexter.pop();
				for (int q = 0;q < vertexs[hoge].size();++q) {
					if (visited[vertexs[hoge][q]] == false) {
						visited[vertexs[hoge][q]] = cnt;
						len[cnt]++;
						nexter.push(vertexs[hoge][q]);
					}
				}
			}
			cnt++;
		}
	}
	for (int i = 0;i < n;++i) {
		if (len[visited[i]]-1 != vertexs[i].size()) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}