#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int inf=1<<30;
const int N=201000;
int _,n,a[2][N],mx1[2][N],mx2[2][N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,0,n) scanf("%d",&a[0][i]);
		rep(i,0,n) scanf("%d",&a[1][i]);
		a[0][0]=-1;
		rep(j,0,2) {
			mx1[j][n]=-inf;
			mx2[j][n]=-inf;
			per(i,0,n) {
				mx1[j][i]=max(mx1[j][i+1],a[j][i]+i);
				mx2[j][i]=max(mx2[j][i+1],a[j][i]-i);
			}
		}
		int ans=inf,cur=-inf,tot=0,s=0;
		rep(i,0,n) {
			//ans=min(ans,max(cur,gao(i,a[s],a[s^1])));
			int v=cur;
			v=max(v,mx2[s][i]-i);
			v=max(v,mx1[s^1][i]-(2*n-1+i));
			ans=min(ans,v);
			//printf("--- %d %d %d\n",i,v,cur);
			cur=max({cur,a[s][i]-tot,a[s^1][i]-(tot+1)});
			tot+=2; s^=1;
		}
		printf("%d\n",ans+2*n);
	}
}