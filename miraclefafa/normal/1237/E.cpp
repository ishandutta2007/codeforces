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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;
int n,dp[N],pd[N][2];
bool mark[10*N];
int main() {
	scanf("%d",&n);
	mark[1]=1;
	mark[2]=1;
	int p=2;
	while (p<=n) {
		mark[p*2]=1;
		mark[p*2+1]=1;
		mark[p*4+1]=1;
		mark[p*4+2]=1;
		p=p*4+2;
//		printf("gg %d\n",p);
	}
	printf("%d\n",mark[n]);
/*	pd[1][1]=0; pd[1][0]=1<<30;
	for (int i=2;i<=n;i++) {
		dp[i]=1<<30;
		for (int j=0;j<=i-1;j++) {
			dp[i]=min(dp[i],dp[j]+dp[i-1-j]+i-1);
		}
		pd[i][0]=pd[i][1]=1<<30;
		for (int j=0;j<=i-1;j++) {
			pd[i][(j+1)%2]=min(pd[i][(j+1)%2],pd[j][j%2]+pd[i-1-j][0]+i-1);
		}
//		printf("%d %d\n",)
		for (int j=0;j<=i-1;j++) {
			if (dp[j]+dp[i-1-j]+i-1==dp[i]) {
//				printf("gg %d %d\n",i,j);
			}
		}
		if (dp[i]==pd[i][i%2]) {
			printf("%d %d %d\n",i,dp[i],pd[i][i%2]);
			for (int j=0;j<=i-1;j++) {
				if (pd[i][(j+1)%2]==pd[j][j%2]+pd[i-1-j][0]+i-1&&pd[i][i%2]==dp[i]) {
				//	printf("%d %d\n",i,j);
				}
			}
		}
	}*/
}