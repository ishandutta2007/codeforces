//#include <bits/stdc++.h>
//
//using namespace std;
//
//using namespace std;
//typedef long long ll;
//typedef vector<int> vi;
//typedef vector<pair<int,int>> vpi;
//
//#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
//#define F0R(i,a) FOR(i,0,a)
//#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
//#define R0F(i,a) ROF(i,0,a)
//#define trav(a,x) for (auto& a: x)
//
//#define pb push_back
//#define rsz resize
//#define all(x) begin(x), end(x)
//#define pi pair<int, int>
//#define mp make_pair
//#define F first
//#define S second
//int n;
//const int MOD = 998244353;
//vi a;
//vector<vector<vi>> dp;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cin >> n;
//    a.rsz(n);
//    F0R(i, n) cin >> a[i];
//    F0R(i, n) if (a[i]>-1) a[i]--;
//    dp.rsz(n+1, vector<vi>(2, vi(200, 0)));
//    if (a[0]==-1) F0R(i, 200) dp[0][0][i]=1;
//    else dp[0][0][a[0]]=1;
//    FOR(ind, 1, n) {
//        if (a[ind]==-1) {
//            FOR(j, 1, 200) {
//                dp[ind][0][j] += dp[ind][0][j-1]+dp[ind-1][0][j-1] + dp[ind-1][1][j-1];
//                dp[ind][0][j] %= MOD;
//            }
//            R0F(j, 200) {
//                if (j<199) dp[ind][1][j] += dp[ind][1][j+1];
//                dp[ind][1][j] += dp[ind-1][1][j];
//                dp[ind][1][j] %= MOD;
//            }
//            F0R(j, 200) {
//                dp[ind][1][j] += dp[ind-1][0][j];
//                dp[ind][1][j] %= MOD;
//            }
//        } else {
//            FOR(j, 0, 200) {
//                if (a[ind]<j) {dp[ind][1][a[ind]] += dp[ind-1][1][j]; dp[ind][1][a[ind]] %= MOD;}
//                else if (a[ind]==j) {dp[ind][1][j] += dp[ind-1][0][j]+dp[ind-1][1][j]; dp[ind][1][j]%=MOD;}
//                else {dp[ind][0][a[ind]] += dp[ind-1][0][j]+dp[ind-1][1][j]; dp[ind][0][a[ind]]%=MOD;}
//            }
//        }
////        int l=0, r=200;
////        FOR(j, l, r) {
////            if (a[ind]==-1) {
////                F0R(k, j) {dp[ind][1][k] += dp[ind-1][1][j]; dp[ind][1][k] %= MOD;}
////                dp[ind][1][j] += dp[ind-1][0][j]+dp[ind-1][1][j];
////                dp[ind][1][j] %= MOD;
////                FOR(k, j+1, 200) {dp[ind][0][k] += dp[ind-1][0][j]+dp[ind-1][1][j]; dp[ind][0][k] %= MOD;}
////            } else {
////                if (a[ind]<j) {dp[ind][1][a[ind]] += dp[ind-1][1][j]; dp[ind][1][a[ind]] %= MOD;}
////                else if (a[ind]==j) {dp[ind][1][j] += dp[ind-1][0][j]+dp[ind-1][1][j]; dp[ind][1][j]%=MOD;}
////                else {dp[ind][0][a[ind]] += dp[ind-1][0][j]+dp[ind-1][1][j]; dp[ind][0][a[ind]]%=MOD;}
////            }
////        }
////        F0R(j, 200) cout << dp[ind][0][j] << ' ';
////        cout << '\n';
////        F0R(j, 200) cout << dp[ind][1][j] << ' ';
////        cout << "\n\n";
//    }
//    int ans = 0;
//    F0R(j, 200) {ans += dp[n-1][1][j]; ans %= MOD;}
//    cout << ans%MOD << '\n';
//}
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
const ll mod=998244353;
const int d=200;

int n;

ll dps[nax][2];
ll dpn[nax][2];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

inline int mog(int v, int i)
{
	if (v==i)
		return 1;
	if (v==-1)
		return i>0;
	return 0;
}

void upd(int v)
{
	for (int i=0; i<=d; i++)
	{
		for (int j=0; j<2; j++)
		{
			dps[i][j]=dpn[i][j];
			dpn[i][j]=0;
		}
	}
	ll s=0;
	for (int i=0; i<=d; i++)
	{
		if (mog(v, i))
			dod(dpn[i][0], s);
		dod(s, dps[i][0]+dps[i][1]);
	}
	s=0;
	for (int i=d; i>=0; i--)
	{
		if (mog(v, i))
			dod(dpn[i][1], s);
		dod(s, dps[i][1]);
	}
	for (int i=0; i<=d; i++)
	{
		if (mog(v, i))
			dod(dpn[i][1], dps[i][0]+dps[i][1]);
	}
}

int main()
{
	scanf("%d", &n);
	dpn[0][1]=1;
	for (int i=1; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		upd(x);
	}
	upd(0);
	printf("%lld\n", dpn[0][1]);
	return 0;
}