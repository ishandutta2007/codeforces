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


const int INF = 1001001001;
const ll LIM = 1001001001001ll;
int N, K;
int A[100001];


int main() {
	char latte[10];
	scanf("%d%d", &N, &K);
	for (int i = 0; i <= N; i++) {
		scanf("%s", latte);
		if (latte[0] == '?') {
			A[i] = INF;
			continue;
		}
		bool m = false;
		int s = 0;
		for (int j = 0; latte[j]; j++) {
			if (latte[j] == '-') {
				m = true;
				continue;
			}
			s = s * 10 + latte[j] - '0';
		}
		A[i] = s;
		if (m)A[i] *= -1;
	}

	int cnt = 0;
	for (int i = 0; i <= N; i++)if (A[i] == INF)cnt++;
	if (cnt) {
		if (K) {
			if (N & 1)puts("Yes");
			else puts("No");
		}
		else {
			if (A[0] == 0)puts("Yes");
			else if (A[0] != INF)puts("No");
			else {
				if ((N + 1 - cnt) & 1)puts("Yes");
				else puts("No");
			}
		}
		return 0;
	}

	ll val = 0;
	for (int i = N; i >= 0; i--) {
		val = val*K + A[i];
		if (abs(val) > LIM) {
			puts("No");
			return 0;
		}
	}

	if (val)puts("No");
	else puts("Yes");
	return 0;
}