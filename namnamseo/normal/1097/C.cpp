#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

map<int,int> cnt;

char s[500010];

int main()
{
	cppio();
	int n; cin>>n;

	int T = 0;
	rep(i, n){
		cin >> s;
		int n = strlen(s);
		int lev = 0, ml = 0;
		rep(j, n){
			if(s[j] == '(') ++lev;
			else --lev;
			ml = min(ml, lev);
		}

		T = max(T, abs(lev));

		if(lev > 0){
			if(ml >= 0) ++cnt[lev];
		} else if(lev < 0){
			if(ml >= lev) ++cnt[lev];
		} else {
			if(ml >= 0) ++cnt[lev];
		}
	}

	ll ans = 0;
	rrep(i, T){
		ll a=cnt[i], b=cnt[-i];
		ans += min(a, b);
	}
	ll a = cnt[0];
	ans += a/2;
	cout << ans << endl;
	return 0;
}