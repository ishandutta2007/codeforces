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

int n,t;
string nam[110];
int d[30],q[30];
VI e[30];
void add(int u,int v) { d[v]++; e[u].pb(v);}
int main() {
	scanf("%d",&n);
	rep(i,0,n) cin>>nam[i];
	rep(i,0,n-1) {
		int l=0;
		while (l<SZ(nam[i])&&l<SZ(nam[i+1])&&nam[i][l]==nam[i+1][l]) ++l;
		if (l>=SZ(nam[i])||l>=SZ(nam[i+1])) {
			if (l>=SZ(nam[i+1])) { puts("Impossible");return 0;}
			continue;
		}
		add(nam[i][l]-'a',nam[i+1][l]-'a');
	}
	rep(i,0,26) if (d[i]==0) q[t++]=i;
	rep(i,0,t) {
		int u=q[i];
		rep(j,0,SZ(e[u])) {
			int v=e[u][j];
			if ((--d[v])==0) q[t++]=v;
		}
	}
	if (t!=26) puts("Impossible");
	else {
		rep(i,0,26) putchar(q[i]+'a');
	}
}