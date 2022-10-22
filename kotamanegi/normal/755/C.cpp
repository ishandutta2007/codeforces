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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 100000000000000
vector<int> vertexs[30000];
int arrival[30000] = {};
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		vertexs[i + 1].push_back(tmp);
		vertexs[tmp].push_back(i + 1);
	}
	int ans = 0;
	for (int i = 1;i <= n;++i) {
		if (arrival[i] == false) {
			queue<int> nexter;
			nexter.push(i);
			ans++;
			arrival[i] = true;
			while (nexter.empty() == false) {
				int next = nexter.front();
				nexter.pop();
				for (int q = 0;q < vertexs[next].size();++q) {
					if (arrival[vertexs[next][q]] == false) {
						arrival[vertexs[next][q]] = true;
						nexter.push(vertexs[next][q]);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}