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

const int N=2010;
int n,m,dpl[N][N],dpu[N][N];
ll su[N][N],sl[N][N];
char s[N][N];
int br[N][N],bd[N][N];
int main() {
	scanf("%d%d",&n,&m);
	if (n==1&&m==1) { puts("1"); return 0; }
	rep(i,0,n) {
		scanf("%s",s[i]);
	}
	rep(i,0,n) {
		per(j,0,m) br[i][j]=br[i][j+1]+(s[i][j]=='R');
	}
	rep(j,0,m) {
		per(i,0,n) bd[i][j]=bd[i+1][j]+(s[i][j]=='R');
	}
	dpl[0][0]=1;
	dpu[0][0]=1;
	sl[0][1]=mod-1;
	su[1][0]=mod-1;
	rep(i,0,n) {
		rep(j,0,m) {
			if (j>0) dpl[i][j]=(dpl[i][j-1]+sl[i][j])%mod;
			if (i>0) dpu[i][j]=(dpu[i-1][j]+su[i][j])%mod;
			su[i+1][j]=(su[i+1][j]+dpl[i][j])%mod;
			su[n-bd[i+1][j]][j]=(su[n-bd[i+1][j]][j]+mod-dpl[i][j])%mod;
			sl[i][j+1]=(sl[i][j+1]+dpu[i][j])%mod;
			sl[i][m-br[i][j+1]]=(sl[i][m-br[i][j+1]]+mod-dpu[i][j])%mod;
		//rep(k,i+1,n-bd[i+1][j]) dpu[k][j]=(dpu[k][j]+dpl[i][j])%mod;
		//rep(k,j+1,n-br[i][j+1]) dpl[i][k]=(dpl[i][k]+dpu[i][j])%mod;
		//	printf("%d %d %d %d\n",i,j,dpl[i][j],dpu[i][j]);
		}
	}
	printf("%lld\n",(dpu[n-1][m-1]+dpl[n-1][m-1])%mod);
}