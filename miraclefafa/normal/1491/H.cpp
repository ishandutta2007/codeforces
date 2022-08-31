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

const int N=101000;
int n,q,blk;
int ljump[N],a[N],dv[N],off[N],lb[N];
void recalc(int T) {
	int L=max(2,T*blk),R=min((T+1)*blk,n+1),toff=off[T];
	//printf("%d %d\n",L,R);
	for (int j=L;j<R;j++) {
		if (a[j]-toff<lb[j]) ljump[j]=max(a[j]-toff,1);
		else ljump[j]=ljump[a[j]-toff];
		//printf("ff %d %d\n",j,ljump[j]);
	}

}
int main() {
	scanf("%d%d",&n,&q);
	blk=int(sqrt(n));
	ljump[1]=1;
	for (int i=2;i<=n;i++) {
		scanf("%d",a+i);
		lb[i]=i/blk*blk;
		dv[i]=i/blk;
		if (a[i]<lb[i]) ljump[i]=a[i]; else ljump[i]=ljump[a[i]];
	}
	rep(i,0,q) {
		int ty;
		scanf("%d",&ty);
		if (ty==1) {
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			if (l/blk==r/blk) {
				rep(j,l,r+1) a[j]=max(a[j]-x,1);
				recalc(l/blk);
			} else {
				int R=min((l/blk+1)*blk,n+1);
				for (int j=l;j<R;j++) a[j]=max(a[j]-x,1);
				recalc(l/blk);
				for (int j=r/blk*blk;j<=r;j++) a[j]=max(a[j]-x,1);
				recalc(r/blk);
				R=r/blk;
				for (int j=l/blk+1;j<R;j++) {
					off[j]=min(off[j]+x,n);
					if (off[j]<=blk) recalc(j);
				}
				//rep(i,1,n+1) printf("%d ",ljump[i]); puts("");
			}
		} else {
			int u,v;
			auto Ajump=[&](int v) {
				return max(1,a[v]-off[dv[v]]);
			};
			auto Ljump=[&](int v) {
				if (off[dv[v]]>blk) return Ajump(v);
				else return ljump[v];
			};
			scanf("%d%d",&u,&v);
			while (1) {
				if (u>v) swap(u,v);
				if (dv[v]>dv[u]) v=Ljump(v);
				else {
					if (Ljump(u)==Ljump(v)) {
						while (u!=v) {
							if (u>v) swap(u,v);
							v=Ajump(v);
						}
						printf("%d\n",v);
						break;
					} else {
						u=Ljump(u); v=Ljump(v);
					}
				}
			}
		}
	}
}