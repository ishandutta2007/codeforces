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

const int N=20100;
int n,m,a,b,p[N],mat[N],t,vis[N];


int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=2*n;i++) scanf("%d",p+i);
	for (int i=0;i<m;i++) {
		scanf("%d%d",&a,&b);
		mat[a]=b;
		mat[b]=a;
	}
	scanf("%d",&t);
	if (t==1) {
		int pre=0;
		for (int i=0;i<n;i++) {
			int lag=-1;
			for (int j=1;j<=2*n;j++) if (mat[j]!=0&&!vis[j]&&(lag==-1||p[j]>p[lag])) {
				lag=j;
			}
			if (lag==-1) {
				for (int j=1;j<=2*n;j++) if (!vis[j]&&(lag==-1||p[j]>p[lag])) {
					lag=j;
				}
			}
			assert(lag!=-1);
			printf("%d\n",lag);
			fflush(stdout);
			vis[lag]=1;
			scanf("%d",&pre);
			vis[pre]=1;
		}
	} else {
		int pre=0;
		for (int i=0;i<n;i++) {
			scanf("%d",&pre);
			vis[pre]=1;
			int lag=-1;
			if (mat[pre]!=0&&vis[mat[pre]]==0) {
				lag=mat[pre];
			} else {
				for (int j=1;j<=2*n;j++) if (mat[j]!=0&&!vis[j]&&(lag==-1||p[j]>p[lag])) {
					lag=j;
				}
				if (lag==-1) {
					for (int j=1;j<=2*n;j++) if (!vis[j]&&(lag==-1||p[j]>p[lag])) {
						lag=j;
					}
				}
			}
			assert(lag!=-1);
			printf("%d\n",lag);
			fflush(stdout);
			vis[lag]=1;
		}
	}
}