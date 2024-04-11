#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef long double db;
mt19937_64 mrand(1); 
const ll mod=1000000007;
ll rnd(ll x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=50100,M=1010000;
int t,q,w[N];
vector<array<db,3>> item[N];
vector<array<db,6>> seg[N],func[N];
db ans[301000];
array<db,4> coef[M];
db len[M],val[M];

db tmpc[10],tmpp[10],sl;
int main() {
	scanf("%d%d",&t,&q);
	rep(i,0,t) {
		int v;
		scanf("%d",&v);
		w[i]=0;
		rep(j,0,v) {
			int c;
			scanf("%d",&c);
			tmpc[j]=c;
			w[i]+=tmpc[j];
		}
		int sp=0;
		rep(j,0,v) {
			int p;
			scanf("%d",&p);
			tmpp[j]=p;
			sp+=p;
		}
		rep(j,0,v) tmpp[j]/=sp;
		rep(j,0,v) if (1.*tmpc[j]/w[i]>tmpp[j]) {
			db extra=tmpc[j]/tmpp[j]-w[i];
			item[i].pb({extra,tmpc[j],tmpp[j]});
		}
		int m=SZ(item[i]);
		sort(all(item[i]));
		db totc=0,totp=0;
		rep(j,0,m) totc+=item[i][j][1],totp+=item[i][j][2];
		rep(j,0,m) {
			db l=(j==0)?0:item[i][j-1][0],r=item[i][j][0];
			db sl=-totc/(w[i]+l)/(w[i]+l),sr=-totc/(w[i]+r)/(w[i]+r);
			seg[i].pb({l,r,sl,sr,totc,totp});
			totc-=item[i][j][1],totp-=item[i][j][2];
		}
		seg[i].pb({item[i].back()[0],1e18,0,0,0,0});
		sl=min(sl,seg[i][0][2]);
	}
	vector<array<int,3>> td;
	vector<db> pr;
	pr.pb(sl);
	rep(i,0,t) {
		rep(j,0,SZ(seg[i])) {
			pr.pb(seg[i][j][2]);
			if (j!=SZ(seg[i])-1) pr.pb(seg[i][j][3]);
		}
	}
	sort(all(pr));
	pr.erase(unique(all(pr)),pr.end());
	auto add=[&](db l, db r, array<db,4> cc) {
		int vl=lower_bound(all(pr),l)-pr.begin()+1;
		int vr=lower_bound(all(pr),r)-pr.begin()+1;
		//printf("oo %d %d %.10Lf %.10Lf\n",vl,vr,l,r);
		//assert(vl<=vr);
		rep(i,0,4) coef[vl][i]+=cc[i];
		rep(i,0,4) coef[vr][i]-=cc[i];
	};
	rep(i,0,t) {
		rep(j,0,SZ(seg[i])) {
			db fl=(j==0)?sl:seg[i][j-1][3];
			db len=seg[i][j][0];
			add(fl,seg[i][j][2],{len,0,seg[i][j][4]/(w[i]+len)-seg[i][j][5],0});
			if (j!=SZ(seg[i])-1) {
				add(seg[i][j][2],seg[i][j][3],{-1.*w[i],sqrt(seg[i][j][4]),-seg[i][j][5],sqrt(seg[i][j][4])});
			}
		}
	}
	int m=SZ(pr);
	rep(i,1,m) {
		rep(j,0,4) coef[i][j]+=coef[i-1][j];
		db x=pr[i];
		len[i]=coef[i][0]+coef[i][1]/sqrt(-x);
		val[i]=coef[i][2]+coef[i][3]*sqrt(-x);
		if (x==0) len[i]=1e18;
		//printf("%.10Le %.10Lf %.10Lf\n",x,len[i],val[i]);
	}
	rep(i,0,q) {
		// cc=rnd(100000000001ll);
		ll cc;
		scanf("%lld",&cc);
		int v=upper_bound(len,len+m,cc)-len;
		if (v>=m-1) {
			puts("0");
			continue;
		} else {
			//assert(cc>coef[v][0]);
			db ans=coef[v][2]+coef[v][3]*(coef[v][1]/(cc-coef[v][0]));
			printf("%.10Lf\n",ans*2);
		}
	}
}