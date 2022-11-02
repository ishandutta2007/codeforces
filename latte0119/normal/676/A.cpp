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
	int n;
	cin >> n;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1 || a == n) {
			ans = max(ans, i);
			ans = max(ans, n - 1 - i);
		}
	}
	cout << ans << endl;
	return 0;
}