//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		ll heal = 1ll * b * c;
		ll ans = 0;
		if (heal < a) ans = -1;
		else {
				ll cur = a / b;
				// 0, d, ..., cur / d * d
				int tr = cur / d;
				ll lst = cur / d * d;
				ll dmg = 1ll * a * tr + a;
				ll hr = 1ll * lst * (lst / d + 1) / 2 * b;
				ans = dmg - hr;
		}
		printf("%lld\n", ans);
	}
	return 0;
}