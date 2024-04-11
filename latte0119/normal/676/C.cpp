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

int N, K;
char S[111111];

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", S);
	
	int ans = 0, r = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		while (r < N) {
			int ns = sum + (S[r] == 'a');
			if (min(ns, r + 1 - i-ns)>K)break;
			r++;
			sum = ns;
		}
		ans = max(ans, r - i);
		sum -= S[i] == 'a';
	}
	cout << ans << endl;
	return 0;
}