#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=1e5, MOD=998244353;
ll n, a[MX];
ll cnt[11];
string A[MX];

ll calcX(string s, ll q) {
	ll tot = 0;
	ll j = 0;
	RE(i,s.size()) {
		if(q > i) j++;
		ll a = s[s.size()-1-i]-'0';
		RE(k,j) a = (a*10)%MOD;
		tot = (tot+a)%MOD;
		j++;
	}
	return tot;
}
ll calcY(string s, ll q) {
	ll tot = 0;
	ll j = 0;
	RE(i,s.size()) {
		ll a = s[s.size()-1-i]-'0';
		RE(k,j) a = (a*10)%MOD;
		tot = (tot+a)%MOD;
		if(q > i) j++;
		j++;
	}
	return tot;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>A[i];
    RE(i,11) cnt[i]=0;
    RE(i,n) cnt[A[i].size()]++;
    ll ans=0;
    RE(i,n) {
    	REP(j,1,11) {
    		ans = (ans+cnt[j]*calcX(A[i],j))%MOD;
    		ans = (ans+cnt[j]*calcY(A[i],j))%MOD;
    	}
    }
    cout<<ans<<endl;
}