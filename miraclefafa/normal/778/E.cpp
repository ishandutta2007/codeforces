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

const int N=1010,M=1002;
ll dp[N][N];
char a[N],b[N][N];
int val[N],cost[N],len[N],ml[N];
PII lab[N];
int n,m,l;
int main() {
	scanf("%s",a);
	m=strlen(a);
	reverse(a,a+m);
	rep(i,m,M+1) a[i]='0';
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s",b[i]);
		l=strlen(b[i]);
		reverse(b[i],b[i]+l);
		rep(j,l,M+1) b[i][j]='0';
		len[i]=l;
	}
	rep(i,0,10) scanf("%d",cost+i);
	memset(dp,0xee,sizeof(dp));
	dp[0][0]=0;
	rep(i,0,n) lab[i]=mp(0,i);
	rep(i,0,M+1) {
		int l=0,r=9;
		if (i==m-1) l=1;
		if (a[i]!='?') l=a[i]-'0',r=a[i]-'0';
		rep(j,0,n) val[j]=b[lab[j].se][i]-'0',ml[j]=max(m,len[lab[j].se]);
		rep(k,l,r+1) {
			int c2=0,d2=0;
			rep(j,0,n) c2+=(val[j]+k>=10),d2+=(val[j]+k==0&&i>=ml[j])?0:cost[(val[j]+k)%10];
			rep(j,0,n+1) {
				dp[i+1][c2]=max(dp[i+1][c2],dp[i][j]+d2);
				if (j<n) {
					c2-=(val[j]+k>=10),d2-=(val[j]+k==0&&i>=ml[j])?0:cost[(val[j]+k)%10];
					c2+=(val[j]+k+1>=10),d2+=cost[(val[j]+k+1)%10];
				}
			}
		}
		rep(j,0,n) lab[j]=mp(val[j]*(n+1)+n-j,lab[j].se);
		sort(lab,lab+n); reverse(lab,lab+n);
	}
	printf("%lld\n",dp[M+1][0]);
}