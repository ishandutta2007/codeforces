#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<sstream>
#include<bitset>
#include<numeric>
#include<climits>
#include<cassert>
#include<complex>
#include<functional>
using namespace std;

typedef long long ll;
template<typename A,typename B>inline void chmin(A &a, B b) { if (a > b)a = b; }
template<typename A,typename B>inline void chmax(A &a, B b) { if (a < b)a = b; }

int main() {
	int n, t;
	cin >> n >> t;
	vector<int>a = { t };
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int s = 1 << i;
		vector<int>aa(i + 2);
		for (int j = 0; j < a.size(); j++) {
			if (a[j] < s)continue;
			ans++;
			a[j] -= s;
			aa[j] += a[j];
			aa[j + 1] += a[j];
		}
		a = aa;
	}
	cout << ans << endl;
	return 0;
}