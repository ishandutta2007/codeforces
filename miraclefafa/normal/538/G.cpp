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

const int N=201000;
ll t[N],x[N],y[N],Tt[N],Tx[N],Ty[N],pmx,pmn,qmx,qmn,ct;
int n,l,p[N];
string s;

bool cmp(int a,int b) { return mp(t[a]%l,t[a])<mp(t[b]%l,t[b]);}
inline ll Div(ll a,ll b) {
	assert(b);
	if (a>=0) return a/b;
	else if (a%b==0) return a/b;
	else return a/b-1;
}
bool add(ll px,ll py,ll pd,ll c) {
	// |dx-px/pd|+|dy-py/pd|<=c/pd
	if (pd<0) px*=-1,py*=-1,pd*=-1;
	if (pd==0) {
		return (abs(px)+abs(py)<=c);
	}
	pmx=min(pmx,Div(px+py+c,pd));
	pmn=max(pmn,Div(px+py-c+pd-1,pd));
	qmx=min(qmx,Div(px-py+c,pd));
	qmn=max(qmn,Div(px-py-c+pd-1,pd));
	// add
	// x-y=(px-py+c)/pd,
	return 1;
}
bool Check(ll dx,ll dy,ll T) {
	return (dx+dy+T)%2==0&&abs(dx)+abs(dy)<=T;
}
void gen(ll dx,ll dy,ll T) {
	if (dx>0) {
		rep(i,0,dx) s.pb('R');
	}
	if (dx<0) {
		rep(i,0,-dx) s.pb('L');
	}
	if (dy>0) {
		rep(i,0,dy) s.pb('U');
	}
	if (dy<0) {
		rep(i,0,-dy) s.pb('D');
	}
	for (int i=0;i<T-abs(dx)-abs(dy);i+=2) s.pb('L'),s.pb('R');
}
bool check(ll dx,ll dy) {
	if ((dx+dy-l)%2!=0) return 0;
	rep(i,0,n) {
		Tx[i]=x[i]-dx*(t[i]/l);
		Ty[i]=y[i]-dy*(t[i]/l);
		Tt[i]=t[i]%l;
	}
	rep(i,0,n) {
		if (i!=n-1) {
			if (!Check(Tx[p[i]]-Tx[p[i+1]],Ty[p[i]]-Ty[p[i+1]],Tt[p[i+1]]-Tt[p[i]])) {
				return 0;
			}
		} else {
			if (!Check(Tx[p[i]]-dx,Ty[p[i]]-dy,l-Tt[p[i]])) {
				return 0;
			}
		}
	}
	rep(i,0,n) {
		if (i!=n-1) {
			gen(Tx[p[i+1]]-Tx[p[i]],Ty[p[i+1]]-Ty[p[i]],Tt[p[i+1]]-Tt[p[i]]);
		} else {
			gen(dx-Tx[p[i]],dy-Ty[p[i]],l-Tt[p[i]]);
		}
	}
	rep(i,0,l) putchar(s[i]); puts("");
	return 1;
}
int main() {
//	freopen("in.txt","r",stdin);
	pmx=qmx=1ll<<62,pmn=qmn=-(1ll<<62);
	scanf("%d%d",&n,&l);
	rep(i,1,n+1) scanf("%I64d%I64d%I64d",t+i,x+i,y+i);
	++n;
	rep(i,0,n) if ((t[i]+x[i]+y[i])%2!=0) {
		puts("NO");
		return 0;
	}
	rep(i,0,n) p[i]=i;
	sort(p,p+n,cmp);
	rep(i,0,n) {
		if (i!=n-1) {
			ll pi=t[p[i]]/l,pj=t[p[i+1]]/l;
			if (!add(x[p[i]]-x[p[i+1]],y[p[i]]-y[p[i+1]],pi-pj,t[p[i+1]]%l-t[p[i]]%l)) {
				puts("NO");
				return 0;
			}
		} else {
			ll pi=t[p[i]]/l;
			if (!add(x[p[i]],y[p[i]],(pi+1),l-t[p[i]]%l)) {
				puts("NO");
				return 0;
			}
		}
	}
	if (pmx<pmn||qmx<qmn) {
		puts("NO");
		return 0;
	}
	ll prx=(qmx+pmx)/2,pry=(pmx-qmx)/2;
	for (ll dx=prx-3;dx<=prx+3;dx++) for (ll dy=pry-3;dy<=pry+3;dy++) {
		if (check(dx,dy)) return 0;
	}
	puts("NO");
}