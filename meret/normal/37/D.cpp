#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<bitset>
#include<cassert>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LDB;
typedef vector<string> VS;

const int N = 105;
const int MD = 1e9 + 7;

int dp[N * N];

int x[N], y[N];

int fact[N * N];
int rfact[N * N];

int pot(int a, int b) {
	int res = 1;
	for (; b > 0; b >>= 1) {
		if (b & 1)
			res = (LL(res) * a) % MD;
		a = (LL(a) * a) % MD;
	}
	return res;
}

int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &x[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &y[i]);
	dp[0] = 1;
	rfact[0] = fact[0] = 1;
	for (int i = 1; i <= 10000; ++i) {
		fact[i] = (fact[i - 1] * LL(i)) % MD;
		rfact[i] = pot(fact[i], MD - 2);
	}
	int spots = 0;
	for (int i = n; i >= 1; --i) {
		spots += y[i];
		for (int j = spots; j >= 0; --j) {
			for (int k = 1; k <= j && k <= y[i]; ++k) {
				dp[j] = (dp[j] + (LL(dp[j - k]) * rfact[k])) % MD;
			}
		}
		for (int k = 0; k < x[i]; ++k) {
			for (int j = 0; j <= spots; ++j) {
				dp[j] = (dp[j + 1] * LL(j + 1)) % MD;
			}
		}
	}
	int sum = 0;
	int res = dp[0];
	for (int i = 1; i <= n; ++i) {
		res = (res * LL(rfact[x[i]])) % MD;
		sum += x[i];
	}
	res = (res * LL(fact[sum])) % MD;
	printf("%d\n", res);
}