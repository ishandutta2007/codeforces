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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef double db;
double pi=acos(-1.);

struct cd{
	db a,b;
	cd () {}
	cd (db a,db b) : a(a),b(b) {}
	cd operator+(const cd&y)const{return (cd){a+y.a,b+y.b};}
	cd operator-(const cd&y)const{return (cd){a-y.a,b-y.b};}
	cd operator*(const cd&y)const{return (cd){a*y.a-b*y.b,a*y.b+b*y.a};}
	cd operator!()const{return (cd){a,-b};};
	db len() { return a*a+b*b; }
};
bool operator < (cd a,cd b) { return a.a<b.a; }

const int N=101000;
int n,n1,n2;
cd p[N],q1[N],r1[N],q2[N],r2[N];

cd gen() {
	return cd(rand()%200000001*1e-4-10000,rand()%200000001*1e-4-10000);
}

cd ang(db x) {
	return cd(cos(x),sin(x));
}

cd rrrrrd(cd p) {
	db x=p.a,y=p.b;
	x=floor(x*100+0.5)*0.01,y=floor(y*100+0.5)*0.01;
	return cd(x,y);
}

db eval(cd p,cd *q,int n) {
	db mxx=-1e6,mnx=1e6,mxy=-1e6,mny=1e6;
	rep(i,0,n) {
		cd z=q[i]*p;
		mxx=max(mxx,z.a);
		mxy=max(mxy,z.b);
		mnx=min(mnx,z.a);
		mny=min(mny,z.b);
	}
	return mxx+mxy-mnx-mny;
}
void recov(cd *q,cd *r,cd p,int n) {
	db mxx=-1e6,mnx=1e6,mxy=-1e6,mny=1e6;
	rep(i,0,n) {
		cd z=q[i]*p;
		mxx=max(mxx,z.a);
		mxy=max(mxy,z.b);
		mnx=min(mnx,z.a);
		mny=min(mny,z.b);
		r[i]=z;
	}
	cd d(-0.5*(mxx+mnx),-0.5*(mxy+mny));
	rep(i,0,n) r[i]=r[i]+d;
}

void gao(cd *q,cd *r,int n) {
	db vl=0,vr=pi/2;
	rep(i,0,50) {
		db fl=(vl+vl+vr)/3,fr=(vl+vr+vr)/3;
		if (eval(ang(-fl),q,n)>eval(ang(-fr),q,n)) vl=fl; else vr=fr;
	}
	recov(q,r,ang(-vl),n);
}

void gen(int n,cd *p,int &n2,cd *q) {
	n2=n+rand()%(n/2+1);
	rep(i,0,n) q[i]=p[i];
	rep(i,n,n2) q[i]=gen();
	db t=rand()%100000000*2e-8*pi;
	cd c=ang(t); cd d=gen();
	rep(i,0,n2) q[i]=rrrrrd(q[i]*c+d);
}

int rk[N],vis1[N],vis2[N],perm[N],mat[N];
cd pnt[N];
PII pr[4][N];
db ret[4],dd[N];

void match(cd *r1,cd *r2,int n1,int n2,int n,PII *pr,db &ret) {
	rep(i,0,n1) rk[i]=i,vis1[i]=0;
	sort(rk,rk+n1,[&](int a,int b) { return r1[a]<r1[b]; });
	rep(i,0,n1) pnt[i]=r1[rk[i]];
	rep(i,0,n2) {
		int z=lower_bound(pnt,pnt+n1,r2[i])-pnt;
		db dis=1e10; int pv=-1;
		rep(j,0,100) {
			bool fd=0;
			if (z+j<n1&&pnt[z+j].a<=r2[i].a+dis) {
				fd=1;
				db w=(pnt[z+j]-r2[i]).len();
				if (w<dis) dis=w,pv=z+j;
			}
			if (z-j>=0&&pnt[z-j].a>=r2[i].a-dis) {
				fd=1;
				db w=(pnt[z-j]-r2[i]).len();
				if (w<dis) dis=w,pv=z-j;
			}
			if (!fd) break;
		}
		mat[i]=pv; dd[i]=dis;
	}
	rep(i,0,n2) perm[i]=i,vis2[i]=0;
	sort(perm,perm+n2,[&](int a,int b) { return dd[a]<dd[b]; });
	int cur=0;
	ret=0;
	rep(i,0,n2) {
		int u=perm[i],v=rk[mat[u]];
		if (vis1[v]) continue;
		pr[cur]=mp(v,u); ret+=dd[u];
		vis2[u]=1; vis1[v]=1;
		cur++;
		if (cur>=n) break;
	}
	if (cur<n) {
		set<int> cand;
		rep(i,0,n1) if (!vis1[i]) cand.insert(i);
		rep(i,0,n2) if (!vis2[i]) {
			pr[cur++]=mp(*cand.begin(),i);
			cand.erase(cand.begin());
			if (cur>=n) break;
		}
	}
/*	int cor=0;
	rep(i,0,n) cor+=pr[i].fi==pr[i].se&&pr[i].fi<n;
	printf("%d %.10f\n",cor,ret);*/
}

int main() {
//	srand(time(0));
//	n=1000+rand()%49001;
//	rep(i,0,n) p[i]=gen();
//	gen(n,p,n1,q1);
//	gen(n,p,n2,q2);
	scanf("%d",&n);
	scanf("%d",&n1); rep(i,0,n1) scanf("%lf%lf",&q1[i].a,&q1[i].b);
	scanf("%d",&n2); rep(i,0,n2) scanf("%lf%lf",&q2[i].a,&q2[i].b);
//	printf("%d %d %d\n",n,n1,n2);
	gao(q1,r1,n1); gao(q2,r2,n2);
	rep(it,0,4) {
		match(r1,r2,n1,n2,n,pr[it],ret[it]);
		cd rot(0,1);
		rep(i,0,n2) r2[i]=r2[i]*rot;
	}
	int z=min_element(ret,ret+4)-ret;
	rep(i,0,n) printf("%d %d\n",pr[z][i].fi+1,pr[z][i].se+1);
}