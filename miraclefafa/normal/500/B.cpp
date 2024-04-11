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

const int N=310;
int f[N],n,p[N],ret[N];
VI pos[N],val[N];
char s[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]);}
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",p+i),f[i]=i;
	rep(i,0,n) {
		scanf("%s",s);
		rep(j,0,n) if (s[j]=='1') f[find(i)]=find(j);
	}
	rep(i,0,n) pos[find(i)].pb(i),val[find(i)].pb(p[i]);
	rep(i,0,n) if (find(i)==i) {
		sort(all(val[i]));
		rep(j,0,SZ(val[i])) ret[pos[i][j]]=val[i][j];
	}
	rep(i,0,n) printf("%d ",ret[i]);
}