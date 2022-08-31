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

const int N=5010;
int n,m,s[N],f[N],h[N],cl[N],cr[N],clr[N];
ll way;
int ans;
PII l[N],r[N];
VI pos[N];
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%d",s+i);
		--s[i];
		pos[s[i]].pb(i);
	}
	rep(i,0,m) {
		scanf("%d%d",f+i,h+i);
		--f[i];
		if (h[i]>SZ(pos[f[i]])) {
			--i; --m;
			continue;
		}
		l[i]=mp(pos[f[i]][h[i]-1],i);
		r[i]=mp(pos[f[i]][SZ(pos[f[i]])-h[i]],i);
	}
	if (m==0) {
		puts("0 1");
		return 0;
	}
	f[m]=-1;
	l[m]=mp(-1,0);
	rep(i,0,m+1) {
		rep(j,0,n) cl[j]=0,cr[j]=0,clr[j]=0;
		rep(j,0,m) {
			if (j!=i) {
				if (f[j]==f[i]) {
					if (r[j].fi>l[i].fi) cr[f[j]]++;
				} else {
					if (l[j]<l[i]&&r[j].fi>l[i].fi) clr[f[j]]++;
					else if (l[j]<l[i]) cl[f[j]]++;
					else if (r[j].fi>l[i].fi) cr[f[j]]++;
				}
			}
		}
		//rep(j,0,n) printf("col: %d cl :%d cr :%d clr %d\n",j,cl[j],cr[j],clr[j]);
		int p1=(i<m); ll p2=1;
		rep(j,0,n) {
			if (j==f[i]) {
				if (cr[j]) p1++,p2=p2*cr[j]%mod;
			} else {
				if (cl[j]==0&&cr[j]==0&&clr[j]==0) continue;
				if (cr[j]==0&&clr[j]==0) {
					p1++; p2=p2*cl[j]%mod;
				} else if (cl[j]==0&&clr[j]==0) {
					p1++; p2=p2*cr[j]%mod;
				} else if (cl[j]==0&&cr[j]==0&&clr[j]==1) {
					p1++; p2=p2*(2*clr[j])%mod;
				} else {
					p1+=2;
					int way=clr[j]*(clr[j]-1);
					way+=cl[j]*cr[j];
					way+=cl[j]*clr[j]+cr[j]*clr[j];
					p2=p2*way%mod;
				}
			}
		}
		//printf("%d %d %lld\n",i,p1,p2);
		if (p1>ans) ans=p1,way=0;
		if (p1==ans) way=(way+p2)%mod;
	}
	printf("%d %lld\n",ans,way);
}