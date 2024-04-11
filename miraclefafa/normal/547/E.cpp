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

const int N=501000;
pair<PII,int> pos[N*2];
int sa[N],l[N],r[N],c[N],sl[N],sr[N],n,q,tot,rk[N*2],p[N*2],ans[N];
char s[N];
vector<PII> qr[N];
void buildSA() {
	rep(i,1,tot+1) rk[i]=p[i];
	rep(j,0,19) {
		rep(i,1,tot+1) pos[i]=mp(mp(rk[i],rk[i+(1<<j)]),i);
		sort(pos+1,pos+tot+1);
		int cnt=0;
		rep(i,1,tot+1) {
			rk[pos[i].se]=cnt;
			cnt+=(pos[i].fi!=pos[i+1].fi);
		}
		if (cnt==tot) break;
	}
	rep(i,1,tot+1) rk[i]++;
	rep(i,1,tot+1) sa[rk[i]]=i;
}
int query(int l,int r,char c,int len) {
	++r; --l;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (p[sa[md]+len-1]>=c) r=md; else l=md;
	}
	return r;
}
void add(int x,int s) { for (;x<=tot;x+=x&-x) c[x]+=s;}
int query(int x) { int s=0; for (;x;x-=x&-x) s+=c[x]; return s;}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) {
		scanf("%s",s);
		int len=strlen(s);
		l[i]=tot+1;
		rep(j,0,len) p[++tot]=s[j]-'a';
		p[++tot]=26+i;
		r[i]=tot;
	}
	buildSA();
	rep(i,1,n+1) {
		int pl=1,pr=tot;
		rep(j,l[i],r[i]) {
			int ql=query(pl,pr,p[j],j-l[i]+1);
			int qr=query(pl,pr,p[j]+1,j-l[i]+1)-1;
			pl=ql; pr=qr;
		}
		sl[i]=pl,sr[i]=pr;
	}
	rep(i,1,q+1) {
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		qr[r].pb(mp(k,i)),qr[l-1].pb(mp(k,-i));
	}
	rep(i,1,n+1) {
		rep(j,l[i],r[i]) add(rk[j],1);
		for (auto p:qr[i]) {
			int id=p.se,w=1;
			if (id<0) w=-1,id*=-1;
			ans[id]+=w*(query(sr[p.fi])-query(sl[p.fi]-1));
		}
	}
	rep(i,1,q+1) printf("%d\n",ans[i]);
}