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

const int N=501000;
int n,a[N],_,m;
set<PII> e1[N],e2[N];
int ins[N],pre[N],ore[N],d[N],d2[N];

vector<vector<array<int,3>>> decompose2(set<PII> *e2,int *d) {
	vector<vector<array<int,3>>> ret;
	stack<int> s;
	memset(ins,0,sizeof(ins));
	rep(i,1,n+1) if (SZ(e2[i])%2==1) {
		assert(s.empty());
		s.push(i); ins[i]=1;
		int u=i; pre[u]=0;
		while (1) {
			if (e2[u].empty()) {
				assert(s.top()==u);
				ins[s.top()]=0; s.pop();
				if (s.empty()) break;
				vector<array<int,3>> pt;
				d[i]++;
				d[u]--;
				while (!s.empty()) {
					pt.pb({s.top(),u,pre[u]});
					u=s.top(); s.pop(); ins[u]=0;
				}
				reverse(all(pt));
				ret.pb(pt);
				break;
			} else {
				auto p=*e2[u].begin();
				ore[abs(p.se)]=p.se>0?1:-1;
				int v=p.fi;
				e2[u].erase(p);
				e2[p.fi].erase({u,-p.se});
				if (ins[v]) {
					while (s.top()!=v) {
						ins[s.top()]=0;
						s.pop();
					}
					u=v;
				} else {
					pre[v]=p.se;
					s.push(v);
					ins[v]=1;
				}
				u=v;
			}
		}
	}

	rep(i,1,n+1) if (SZ(e2[i])) {
		assert(SZ(e2[i])%2==0);
		s.push(i); ins[i]=1;
		int u=i; pre[u]=0;
		while (1) {
			if (e2[u].empty()) {
				assert(u==i);
				break;
			} else {
				auto p=*e2[u].begin();
				ore[abs(p.se)]=p.se>0?1:-1;
				int v=p.fi;
				e2[u].erase(p);
				e2[p.fi].erase({u,-p.se});
				if (ins[v]) {
					while (s.top()!=v) {
						ins[s.top()]=0;
						s.pop();
					}
					u=v;
				} else {
					pre[v]=p.se;
					s.push(v);
					ins[v]=1;
				}
				u=v;
			}
		}
	}


	rep(i,1,n+1) assert(SZ(e2[i])==0);
	return ret;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m+1) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		d[u]+=w;
		d[v]+=w;
		if (w==2) {
			e2[u].insert({v,i});
			e2[v].insert({u,-i});
		} else {
			e1[u].insert({v,i});
			e1[v].insert({u,-i});
		}
	}
	int cnt=0;
	rep(i,1,n+1) if (d[i]%2==1) cnt++;
	printf("%d\n",cnt);
	auto ret=decompose2(e2,d2);
	//rep(i,1,m+1) printf("%d\n",ore[i]);
	for (auto x:ret) {
		//puts("pt");
		//for (auto p:x) printf("%d %d %d\n",p[0],p[1],p[2]);
	}
	rep(i,1,n+1) d2[i]*=2;
	int M=m;
	for (auto p:ret) {
		int u=p[0][0],v=p.back()[1];
		++M;
		e1[u].insert({v,M});
		e1[v].insert({u,-M});
	}
	//rep(i,1,n+1) printf("%d ",d2[i]); puts("");
	auto ret2=decompose2(e1,d2);
	//rep(i,1,n+1) printf("%d ",d2[i]); puts("");
	rep(j,0,SZ(ret)) {
		auto p=ret[j];
		int u=p[0][0],v=p.back()[1];
		int M=m+1+j;
		if (ore[M]==1) --d2[u],++d2[v];
		else ++d2[u],--d2[v];
		//printf("%d %d\n",d2[u],d2[v]);
		if (d2[u]==3||d2[v]==-3) {
			d2[u]-=2;
			for (auto x:p) ore[abs(x[2])]*=-1;
			d2[v]+=2;
		}
	}
	//rep(i,1,n+1) printf("zzz %d %d\n",d[i],d2[i]);
	rep(i,1,n+1) if (d[i]%2==1) assert(d2[i]==1||d2[i]==-1);
	rep(i,1,m+1) putchar(ore[i]==1?'1':'2');
	puts("");

}