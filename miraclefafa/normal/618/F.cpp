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

const int N=1010000;
PII a[N],b[N],sp[N*2];
VI pl,pr;
int rl,rr,n,p[N*2];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&a[i].fi),a[i].se=i+1;
	rep(i,0,n) scanf("%d",&b[i].fi),b[i].se=i+1;
	sort(a,a+n); reverse(a,a+n);
	sort(b,b+n); reverse(b,b+n);
	int l=0,r=0,s=0,c=0;
	memset(p,-1,sizeof(p));
	p[n]=0; rl=-1; rr=-1;
	while (1) {
		if (s>0) {
			if (l==n) break;
			s-=a[l].fi;
			sp[c]=mp(a[l].se,0);
			l++;
		} else {
			if (r==n) break;
			s+=b[r].fi;
			sp[c]=mp(b[r].se,1);
			r++;
		}
		if (p[n+s]!=-1) {
			rl=p[n+s],rr=c+1;
			break;
		}
		p[n+s]=++c;
	}
	if (rl==-1) {
		puts("-1");
	} else {
		rep(i,rl,rr) {
			if (sp[i].se==0) pl.pb(sp[i].fi);
			else pr.pb(sp[i].fi);
		}
	}
	printf("%d\n",SZ(pl));
	for (auto u:pl) printf("%d ",u); puts("");
	printf("%d\n",SZ(pr));
	for (auto u:pr) printf("%d ",u); puts("");
}