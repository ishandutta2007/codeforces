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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=810;
int p[N],pos[N],val[N],rem,n;

int cval[N],ccnt;

bool ask(VI x) {
	ccnt++;
	if (SZ(x)==1) return 1;
	printf("? %d",SZ(x));
	for (auto y:x) printf(" %d",y);
	puts("");
	fflush(stdout);
	int t=0;
	scanf("%d",&t);
	return t;
	int s=0;
	for (auto y:x) s+=cval[y];
	return s%SZ(x)==0;
	return t;
}

void dist(int l,int r) {
	VI x;
	rep(i,1,n+1) if (val[i]==0) x.pb(i);
	random_shuffle(all(x));
	if (rem==1) {
		VI rr;
		for (auto y:x) {
			VI xx;
			for (auto z:x) if (z!=y) xx.pb(z);
			if (ask(xx)) rr.pb(y);
			if (SZ(rr)>=2) break;
		}
		pos[1]=rr[0];
		val[rr[0]]=1;
		pos[n]=rr[1];
		val[rr[1]]=n;
		return;
	}
	VI fl;
	for (auto y:x) if (p[y]==l%rem) fl.pb(y);
	rep(i,0,SZ(fl)) {
		int y=fl[i];
		if (i==SZ(fl)-1) { pos[l]=y; val[y]=l; break; }
		VI xx;
		for (auto z:x) if (z!=y) xx.pb(z);
		if (ask(xx)) {
			pos[l]=y;
			val[y]=l;
			break;
		}
	}
	VI fr;
	for (auto y:x) if (p[y]==r%rem) fr.pb(y);
	rep(i,0,SZ(fr)) {
		int y=fr[i];
		if (i==SZ(fr)-1) { pos[r]=y; val[y]=r; break; }
		VI xx;
		for (auto z:x) if (z!=y) xx.pb(z);
		if (ask(xx)) {
			pos[r]=y;
			val[y]=r;
			break;
		}
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) cval[i]=i;
	random_shuffle(cval+1,cval+n+1);
	rem=1;
	dist(1,n);
	rem=2;
	for (int i=1;i<=n;i++) if (val[i]==0) {
		if (ask(VI{pos[1],i})) p[i]=1;
		else p[i]=0;
	}
	for (int i=2;i<=n/2;i++) {
		dist(i,n+1-i);
		if (i==rem) {
			rep(j,1,n+1) if (val[j]==0) {
				int z1=p[j],z2=p[j]+rem;
				if (z2>n) continue;
				int ps=(n+1)*rem;
				int x=(ps+z1)%(2*rem);
				if (x>=1&&x<=rem) {
					VI yy;
					rep(i,1,rem+1) {
						if (i!=x) yy.pb(pos[i]);
						yy.pb(pos[n+1-i]);
					}
					yy.pb(j);
					if (ask(yy)) p[j]=z1; else p[j]=z2;
				} else {
					x=(ps+z2)%(2*rem);
					assert(x>=1&&x<=rem);
					VI yy;
					rep(i,1,rem+1) {
						if (i!=x) yy.pb(pos[i]);
						yy.pb(pos[n+1-i]);
					}
					yy.pb(j);
					if (ask(yy)) p[j]=z2; else p[j]=z1;
				}
			}
			rem*=2;
		}
	}
	if (val[1]>n/2) {
		rep(i,1,n+1) val[i]=n+1-val[i];
	}

	if (cval[1]>n/2) {
		rep(i,1,n+1) cval[i]=n+1-cval[i];
	}

	printf("!");
	rep(i,1,n+1) printf(" %d",val[i]);
	puts("");
	rep(i,1,n+1) {
		//assert(val[i]==cval[i]);
	}
	fprintf(stderr,"%d\n",ccnt);
}