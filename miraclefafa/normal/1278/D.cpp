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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;

int n,f[N];
map<int,int> hs;
PII p[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d%d",&p[i].fi,&p[i].se);
	}
	for (int i=0;i<n;i++) f[i]=i;
	sort(p,p+n);
	for (int i=0;i<n;i++) {
		int u=p[i].fi;
		while (1) {
			auto it=hs.upper_bound(u);
			if (it==hs.end()||it->fi>p[i].se) break;
			int p=i,q=it->se;
			if (find(p)==find(q)) {
				puts("NO");
				return 0;
			}
			u=it->fi;
			f[find(p)]=find(q);
		}
		hs[p[i].se]=i;
	}
	for (int i=0;i<n;i++) if (find(i)!=find(0)) {
		puts("NO");
		return 0;
	}
	puts("YES");
}