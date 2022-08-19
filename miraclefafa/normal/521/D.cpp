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

struct frac {
	ll a,b;
	frac() {}
	frac(ll a,ll b):a(a),b(b) {}
};
bool operator <(const frac &a,const frac &b) {
//	a.a/a.b<b.a/b.b
	return a.a*b.b<a.b*b.a;
}
priority_queue<pair<frac,int> > hp;
const int N=101000;
int k,n,m;
int t[N],id[N],b[N],cd[N];
ll a[N];
vector<PII> ad[N],mu;
VI ans;
PII ass[N];
int main() {
	scanf("%d%d%d",&k,&n,&m);
	rep(i,1,k+1) scanf("%I64d",a+i),ass[i]=mp(-1,0);
	rep(i,1,n+1) {
		scanf("%d%d%d",t+i,id+i,b+i);
		if (t[i]==1) {
			ass[id[i]]=max(ass[id[i]],mp(b[i],i));
		} else if (t[i]==2) {
			ad[id[i]].pb(mp(b[i],i));
		} else {
			mu.pb(mp(b[i],i));
		}
	}
	sort(all(mu)); reverse(all(mu));
	while (SZ(mu)<=m) mu.pb(mp(1,-1));
	rep(i,1,k+1) if (ass[i].fi>a[i]) ad[i].pb(mp(ass[i].fi-a[i],ass[i].se));
	rep(i,1,k+1) {
		cd[i]=0;
		sort(all(ad[i]));
		reverse(all(ad[i]));
		if (!ad[i].empty()) {
			hp.push(mp(frac(ad[i][0].fi,a[i]),ad[i][0].se));
		}
	}
	rep(i,0,m) {
		if (hp.empty()) break;
		frac cur=hp.top().fi; int op=hp.top().se;
		hp.pop();
		int d=id[op];
		a[d]+=cur.a;
		cd[d]++;
		if (SZ(ad[d])>cd[d]) hp.push(mp(frac(ad[d][cd[d]].fi,a[d]),ad[d][cd[d]].se));
		int curb=mu[m-i-1].fi-1;
		if (cur.a<=curb*cur.b) break;
		ans.pb(op);
	}
	rep(j,0,m) {
		if (SZ(ans)==m||mu[j].se==-1) break;
		ans.pb(mu[j].se);
	}
	printf("%d\n",SZ(ans));
	for (int p:ans) if (t[p]==1) printf("%d ",p);
	for (int p:ans) if (t[p]==2) printf("%d ",p);
	for (int p:ans) if (t[p]==3) printf("%d ",p);
}