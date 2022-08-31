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

const int N=110;
int dx[]={-2,-2,-1,-1,1,1,2,2},dy[]={-1,1,-2,2,-2,2,-1,1};
int g[N][N],mark[N];
VI e[N];
map<string,int> hs;
string lst[N];
int n;
vector<PII> ret;
vector<int> findpath(int i,int j) {
	VI v;
	v.pb(i);
	while (i!=j) {
		for (auto k:e[i]) {
			if (g[k][j]+1==g[i][j]) {
				v.pb(k);
				i=k;
				break;
			}
		}
	}
	return v;
}
int main() {
	rep(i,0,64) rep(j,0,64) g[i][j]=(i==j)?0:100000;
	rep(i,0,8) rep(j,0,8) {
		string name{(char)('a'+j),char('1'+i)};
		lst[i*8+j]=name;
		hs[name]=i*8+j;
		rep(k,0,8) {
			int nx=i+dx[k],ny=j+dy[k];
			if (nx>=0&&nx<8&&ny>=0&&ny<8) {
				e[i*8+j].pb(nx*8+ny);
				g[i*8+j][nx*8+ny]=1;
			}
		}
	}
	rep(k,0,64) rep(i,0,64) rep(j,0,64) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	scanf("%d",&n);
	rep(i,0,n) {
		string s;
		cin>>s;
		mark[hs[s]]=1;
	}
	rep(i,0,n) {
		int ds=-1;
		rep(j,i,64) if (mark[j]==1) {
			if (ds==-1||g[ds][i]>g[j][i]) {
				ds=j;
			}
		}
		assert(ds!=-1);
		VI pt=findpath(i,ds);
		int pre=0;
		auto movee=[&](int u,int v) {
			assert(mark[u]);
			assert(!mark[v]);
			mark[v]=mark[u];
			mark[u]=0;
			ret.pb(mp(u,v));
		};
		rep(i,0,SZ(pt)) {
			if (mark[pt[i]]!=0) {
				per(j,pre,i) {
					movee(pt[j+1],pt[j]);
				}
				pre=i;
			}
		}
		rep(j,0,i+1) assert(mark[j]);
	}
	printf("%d\n",SZ(ret));
	rep(i,0,SZ(ret)) {
		printf("%s-%s\n",lst[ret[i].fi].c_str(),lst[ret[i].se].c_str());
	}
}