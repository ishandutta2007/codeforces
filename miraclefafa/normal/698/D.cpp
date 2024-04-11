#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int N=1010;
int k,n,ax[N],ay[N],px[N],py[N];
vector<PII> vec[N];
map<PII,int> hs;
VI pr[10][N];
int sht[N],vis[N];
int gcd(int x,int y) { return x?gcd(y%x,x):y; }
bool dfs(int rm,VI c) {
/*	puts("-----state begin-----");
	printf("%d\n",rm);
	for (auto v:c) printf("%d ",v); puts("");
	rep(i,0,n) printf("%d ",sht[i]); puts("");
	rep(i,0,k) printf("%d ",vis[i]); puts("");
	puts("-----state end-----");*/
	if (SZ(c)==0) return 1;
	if (SZ(c)>rm) return 0;
	for (auto v:c) {
		sht[v]=1;
		rep(j,0,k) if (!vis[j]&&SZ(pr[j][v])<=7) {
			vis[j]=1;
			bool val=1;
			set<int> d(all(c)); d.erase(v);
			for (auto pp:pr[j][v]) {
//				printf("%d %d %d\n",j,v,pp);
				if (sht[pp]) {
					val=0;
					break;
				}
				d.insert(pp);
				if (SZ(d)>rm) {
					val=0; break;
				}
			}
			if (val) {
				if (dfs(rm-1,VI(all(d)))) return 1;
			}
			vis[j]=0;
		}
		sht[v]=0;
	}
	return 0;
}
int main() {
	scanf("%d%d",&k,&n);
	rep(i,0,k) scanf("%d%d",ax+i,ay+i);
	rep(i,0,n) scanf("%d%d",px+i,py+i);
	rep(z,0,k) {
		rep(j,0,n+1) vec[j].clear();
		hs.clear();
		int tot=0;
		rep(j,0,n) {
			int x=px[j]-ax[z];
			int y=py[j]-ay[z];
			int d=gcd(x,y);
			d=abs(d);
			x/=d; y/=d;
			if (!hs.count(mp(x,y))) hs[mp(x,y)]=tot++;
			vec[hs[mp(x,y)]].pb(mp(d,j));
		}
		rep(i,0,tot) {
			sort(all(vec[i]));
			VI v;
			for (auto p:vec[i]) {
				pr[z][p.se]=v;
//				printf("%d ",p.se);
				v.pb(p.se);
			}
//			puts("");
		}
//		puts("----");
	}
	int ret=0;
	rep(i,0,n) {
		memset(sht,0,sizeof(sht));
		memset(vis,0,sizeof(vis));
		if (dfs(k,VI{i}))ret++;
	}
	printf("%d\n",ret);
}