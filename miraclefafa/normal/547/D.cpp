#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int n, m, a, b, l = -1,col[1010000];
VI e;
multiset<PII> al[401000];
void go(int at) {
	while (!al[at].empty()) {
		PII ret=*al[at].begin();
		int to =ret.fi,id=ret.se;
		al[at].erase(al[at].find(mp(to,id)));
		al[to].erase(al[to].find(mp(at,id)));
		go(to);
		e.pb(id);
	}
}
int main() {
	scanf("%d", &n); m=n;
	rep(i,0,n) {
		scanf("%d%d",&a,&b); b+=200001;
		al[a].insert(mp(b,i)); al[b].insert(mp(a,i));
	}
	rep(i,1,400003) if (al[i].size()%2) {
		if (i<200001) {
			al[i].insert(mp(400002,m));
			al[400002].insert(mp(i,m)); ++m;
		} else {
			al[i].insert(mp(200001,m));
			al[200001].insert(mp(i,m)); ++m;
		}
	}
	rep(i,1,400003) go(i);
	rep(i,0,SZ(e)) col[e[i]]=i%2;
	rep(i,0,n) putchar(col[i]?'r':'b');
}