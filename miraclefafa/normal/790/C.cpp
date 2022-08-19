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

const int N=80;
int n,pos[10][N],t[10],dp[N][N][N][4],sm[4][4][N][N];
char s[N];
void upd(int &a,int b) { if (a>b) a=b;}
int main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	rep(i,1,n+1) {
		if (s[i]=='V') {
			pos[0][++t[0]]=i;
		} else if (s[i]=='K') {
			pos[1][++t[1]]=i;
		} else {
			pos[2][++t[2]]=i;
		}
	}
	rep(p,0,3) rep(q,0,3) if (p!=q) {
		rep(i,1,t[p]+1) {
			int c=0;
			rep(j,1,t[q]+1) {
				c+=pos[p][i]<pos[q][j];
				sm[p][q][i][j]=c;
			}
		}
	}
	memset(dp,0x20,sizeof(dp));
	dp[0][0][0][2]=0;
	rep(p1,0,t[0]+1) rep(p2,0,t[1]+1) rep(p3,0,t[2]+1) rep(p4,0,3) {
//		if (dp[p1][p2][p3][p4]<10000) printf("%d %d %d %d %d\n",p1,p2,p3,p4,dp[p1][p2][p3][p4]);
		if (p1!=t[0]) {
			upd(dp[p1+1][p2][p3][0],dp[p1][p2][p3][p4]+sm[0][1][p1+1][p2]+sm[0][2][p1+1][p3]);
		}
		if (p2!=t[1]&&p4!=0) {
			upd(dp[p1][p2+1][p3][1],dp[p1][p2][p3][p4]+sm[1][0][p2+1][p1]+sm[1][2][p2+1][p3]);
		}
		if (p3!=t[2]) {
			upd(dp[p1][p2][p3+1][2],dp[p1][p2][p3][p4]+sm[2][0][p3+1][p1]+sm[2][1][p3+1][p2]);
		}
	}
	int ans=0x20202020;
	rep(p4,0,3) upd(ans,dp[t[0]][t[1]][t[2]][p4]);
	printf("%d\n",ans);
}