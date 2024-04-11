#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll,ll,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=5000, MOD=1e9+7;;
ll n, x[MX], y[MX], c[MX], k[MX], m;
priority_queue<iii, viii, greater<iii>> pq;
ll p[MX], r[MX];

void addEdge(ll i, ll j, ll d) {
	pq.push({d,i,j});
}
void buildDSU() {
	RE(i,m) p[i]=i, r[i]=0;
}
ll getSet(ll i) {return p[i]==i ? i : p[i]=getSet(p[i]);}
bool isSameSet(ll i, ll j) {return getSet(i) == getSet(j);}
void unionSet(ll i, ll j) {
	if(!isSameSet(i, j)) {
		i = getSet(i), j = getSet(j);
		if(r[i] > r[j]) {
			p[j] = i;
		} else {
			p[i] = j;
			if(r[i] == r[j]) r[j]++;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; m = n+1;
    RE(i,n) cin>>x[i]>>y[i];
    RE(i,n) cin>>c[i];
    RE(i,n) cin>>k[i];
    RE(i,n) RE(j,n) {
    	addEdge(i, j, (abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]));
    }
    RE(i,n)
    	addEdge(i,n,c[i]);
    ll minCost=0;
    vi powerStations;
    vii connections;
    buildDSU();
    while(!pq.empty()) {
    	ll d, i, j;
    	tie(d, i, j) = pq.top(); pq.pop();
    	if(!isSameSet(i, j)) {
    		unionSet(i, j);
    		minCost += d;
    		if(j == n)	powerStations.pb(i+1);
    		else		connections.pb({i+1,j+1});
    	}
    }
    cout<<minCost<<endl;
    cout<<powerStations.size()<<endl;
    RE(i,powerStations.size()) cout<<(i==0?"":" ")<<powerStations[i]; cout<<endl;
    cout<<connections.size()<<endl;
    for(ii p : connections)
    	cout<<p.fi<<" "<<p.se<<endl;
}