#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
vector<int> vertexs[200000];
int wow[200000];
int dijk[200000] = {};
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int a;
		cin >> a;
		vertexs[a].push_back(i);
	}
	queue<int> next;
	next.push(1);
	while (next.empty() == false) {
		int hoge = next.front();
		next.pop();
		for (int i = 0; i < vertexs[hoge].size(); ++i) {
			if (dijk[vertexs[hoge][i]] == 0) {
				dijk[vertexs[hoge][i]] = dijk[hoge] + 1;
				wow[dijk[vertexs[hoge][i]]]++;
				next.push(vertexs[hoge][i]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 100000; ++i) {
		ans += wow[i] % 2;
	}
	cout << ans + 1 << endl;
	return 0;
}