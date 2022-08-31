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

const int N=1010;
int n,x,ty[N],num[N],fz[N][2];
char s[N][N];
VI gr[N];
PII p[N];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&x);
		p[i]=mp(x,i);
	}
	sort(p,p+n); reverse(p,p+n);
	rep(i,0,n+1) ty[i]=0;
	rep(i,0,n) {
		rep(j,0,n+1) gr[j].clear();
		rep(j,0,n+1) gr[ty[j]].pb(j);
		int f0=n+1-p[i].fi,f1=p[i].fi;
		rep(j,0,n+1) ty[j]=-1;
		int z=0;
		rep(j,0,n+1) if (SZ(gr[j])>=2&&f0&&f1) {
			f0--; f1--;
			ty[gr[j][0]]=z;
			num[gr[j][0]]=0;
			ty[gr[j][1]]=z+1;
			num[gr[j][1]]=1;
			fz[j][0]=z; fz[j][1]=z+1;
			z+=2;
		} else {
			fz[j][0]=fz[j][1]=z;
			z+=1;
		}
		rep(j,0,n+1) {
			rep(k,0,SZ(gr[j])) {
				if (ty[gr[j][k]]!=-1) continue;
				if (f0) f0--,ty[gr[j][k]]=fz[j][0],num[gr[j][k]]=0;
				else f1--,ty[gr[j][k]]=fz[j][1],num[gr[j][k]]=1;
			}
		}
		//rep(j,0,n+1) printf("%d ",ty[j]); puts("");
		rep(j,0,n+1) s[j][p[i].se]=num[j]+'0';
	}
	printf("%d\n",n+1);
	rep(i,0,n+1) printf("%s\n",s[i]);
}