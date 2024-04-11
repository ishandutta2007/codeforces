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
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=4e5, MOD=1e9+7;
int n, m, ans=0;
vi adjList[MX];
int p[MX], r[MX], L[MX], R[MX];
bool joined[MX];

void buildDSU() {
	RE(i,n) p[i]=L[i]=R[i]=i;
	RE(i,n) r[i]=joined[i]=0;
}
int getSet(int i) {return i==p[i] ? i : p[i]=getSet(p[i]);}
bool isSameSet(int i, int j) {return getSet(i)==getSet(j);}
void unionSet(int i, int j) {
	if(!isSameSet(i,j)) {
		i = getSet(i), j = getSet(j);
		if(r[i] > r[j]) {
			p[j] = i;
			L[i] = min(L[i], L[j]);
			R[i] = max(R[i], R[j]);
		} else {
			p[i] = j;
			L[j] = min(L[i], L[j]);
			R[j] = max(R[i], R[j]);
			if(r[i] == r[j]) r[j]++;
		}
	}
}

void joinSet(int u) {
	u = getSet(u);
	int b=R[u]+1;
	int e=R[u];
	while(b != L[u] || e != R[u]) {
		ll nb = L[u];
		REP(i,nb,b) {
			if(!isSameSet(u,i)) {
				unionSet(u,i);
				ans++;
				u = getSet(u);
			}
		}
		b = nb;
		ll ne = R[u];
		REP(i,e+1,ne+1) {
			if(!isSameSet(u,i)) {
				unionSet(u,i);
				ans++;
				u = getSet(u);
			}
		}
		e = ne;
	}
	joined[u] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    buildDSU();
    RE(i,m) {
    	int u, v;
    	cin>>u>>v; u--; v--;
    	unionSet(u,v);
    }
    RE(i,n) {
    	if(!joined[getSet(i)]) {
    		joinSet(getSet(i));
    	}
    }
    cout<<ans<<endl;
}