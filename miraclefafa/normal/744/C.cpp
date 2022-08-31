#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int N=20;
int n,r[N],b[N],pr,pc,sr[N],sb[N],op[N];
int dp[(1<<16)+20][123];
char ty[10];
void upd(int &a,int b) { if (b>a) a=b;}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s%d%d",ty,r+i,b+i);
		op[i]=(ty[0]=='R');
		pr+=r[i], pc+=b[i];
	}
	memset(dp,0xe0,sizeof(dp));
	dp[0][0]=0;
	rep(S,0,(1<<n)) {
		int tr=0,tb=0;
		rep(i,0,n) if ((S>>i)&1) {
			if (op[i]) tr++; else tb++;
		}
		rep(i,0,n) if (((S>>i)&1)==0) {
			sr[i]=min(r[i],tr); sb[i]=min(b[i],tb);
		}
		rep(i,0,121) if (dp[S][i]>=0) {
			rep(j,0,n) if (((S>>j)&1)==0) upd(dp[S|(1<<j)][i+sr[j]],dp[S][i]+sb[j]);
		}
	}
	int ts=max(pr,pc);
	rep(i,0,121) if (dp[(1<<n)-1][i]>=0) ts=min(ts,max(pr-i,pc-dp[(1<<n)-1][i]));
	printf("%d\n",ts+n);
}