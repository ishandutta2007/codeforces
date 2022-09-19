#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) {
		LL a, b, x;
		scanf("%lld%lld%lld", &a, &b, &x);
		if(a < b) swap(a, b);
		bool ok = x == b;
		while(b != 0) {
			if(x <= a && a % b == x % b) ok = true;
			a %= b; swap(a, b); 
		}
		printf(ok ? "YES\n" : "NO\n");
	}
	return 0;
}