#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1001000
int f[110][110], n, m;
long long N = 1;

inline ll odl(ll a, ll b ){ 
	return max(a-b, b-a);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=100; ++i)
		if (N <= INF / n) N *= n;
	
	while (m != 0)
	{
		if (m > 0) {
			if (odl(m - N, 0) <= m) m -= N;
		}
		else {
			if (odl(m + N, 0) <= -m) m += N;
		}	
		if (N == 1) break;
		N/=n;
	}
	if (m == 0) OUT("Yes");
	OUT("No");
}