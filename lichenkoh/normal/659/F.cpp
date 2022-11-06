#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=1004;
const ll MAXNS=MAXN*MAXN;
ll a[MAXN][MAXN];
ll b[MAXN][MAXN];
ll par[MAXNS];
ll s[MAXNS];
ll f(ll x,ll y) {
	return x*(MAXN-2)+y;
}

ll gfind(ll x) {
	if (par[x]!=x) {
		par[x]=gfind(par[x]);
	}
	return par[x];
}

void gunion(ll x, ll y) {
	ll xr=gfind(x);
	ll yr=gfind(y);
	if (xr==yr) return;
	if (s[xr]>s[yr]) swap(xr,yr);
	par[xr]=yr;
	s[yr]+=s[xr];
	s[xr]=0;
}


void requnion(ll x,ll y, ll p, ll q, ll t) {
	if (a[x][y]<t||a[p][q]<t) return;
	gunion(f(x,y),f(p,q));
}
ll gleft;
bool seen[MAXN][MAXN];
void dfs(ll x, ll y, ll t) {
	seen[x][y]=true;
	if(gleft<=0) return;
	if (a[x][y]<t) return;
	b[x][y]=t;
	gleft--;
	if(gleft<=0) return;
	if (!seen[x+1][y])dfs(x+1,y,t);
	if (!seen[x-1][y])dfs(x-1,y,t);
	if (!seen[x][y+1])dfs(x,y+1,t);
	if (!seen[x][y-1])dfs(x,y-1,t);
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n,m,k; scanf("%I64d %I64d %I64d",&n,&m,&k);
	for (ll i=0;i<MAXN;i++) {
		for (ll j=0;j<MAXN;j++) {
			a[i][j]=0;
			b[i][j]=0;
			seen[i][j]=false;
		}
	}
	for (ll i=0;i<MAXNS;i++) {
		par[i]=i;
		s[i]=1;
	}
	set<ll,greater<ll> > st;
	map<ll,vector<pair<ll,ll> >, greater<ll> > h;
	for (ll i=0;i<n;i++) {
		for (ll j=0;j<m;j++) {
			ll x;
			scanf("%I64d",&x);
			a[i+1][j+1]=x;
			h[x].PB(MP(i+1,j+1));
			if((k%x)==0) {
				//printf("k:%I64d x:%I64d\n",k,x);
				st.insert(x);
			}
		}
	}
	auto hit=h.begin();
	for (auto &t:st) {
		//printf("t:%I64d\n",t);
		while(hit!=h.end() && hit->first>=t) {
			auto v=hit->second;
			for (auto &p: v) {
				ll x=p.first,y=p.second;
				//printf("U:%I64d %I64d\n",x,y);
				requnion(x,y,x+1,y,t);
				requnion(x,y,x-1,y,t);
				requnion(x,y,x,y+1,t);
				requnion(x,y,x,y-1,t);
			}
			++hit;
		}
		{
			auto v=h[t];
			for (auto &p: v) {
				ll sz=s[gfind(f(p.first,p.second))];
				//printf("%I64d %I64d: %I64d\n",p.first,p.second,sz);
				if (sz*t>=k) {
					// Answer found!!
					printf("YES\n");
					gleft=k/t;
					dfs(p.first,p.second,t);
					for (ll x=0;x<n;x++) {
						for (ll y=0;y<m;y++) {
							printf("%I64d ",b[x+1][y+1]);
						}
						printf("\n");
					}
					return 0;
				}
			}
		}
	}
	printf("NO\n");
}