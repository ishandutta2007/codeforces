#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e5, MOD=1e9+7;
int n, k, a;
map<int, int> cnt;
map<vii, int> factCnt;

vii getPrimeFact(int x) {
	vii f;
	for(int i=2; i*i<=x; i++) {
		if(x % i) continue;
		int cnt=0;
		while(x % i == 0)
			x /= i, cnt++;
		cnt %= k;
		if(cnt != 0)
			f.pb({i, cnt});
	}
	if(x > 1) f.pb({x,1});
	return f;
}
vii getReverse(vii f) {
	RE(i,f.size())
		f[i].se = k-f[i].se;
	return f;
}
void print(vii a) {
	RE(i,a.size()) cout<<(i==0?"":" ")<<a[i].fi; cout<<endl;
	RE(i,a.size()) cout<<(i==0?"":" ")<<a[i].se; cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    RE(i,n) cin>>a, cnt[a]++;
    for(ii p : cnt) {
    	vii f = getPrimeFact(p.fi);
    	factCnt[f] += p.se;
    }
    ll ans=0;
    for(auto it=factCnt.begin(); it!=factCnt.end(); ++it) {
    	vii r = getReverse(it->fi);
    	// cout<<it->se<<endl;
    	// print(it->fi);
    	if(r == it->fi) {
    		ans += ll(it->se) * ll(it->se-1);
    	} else {
    		ans += ll(it->se) * ll(factCnt[r]);
    	}
    }
    ans /= 2;
    cout<<ans<<endl;
}