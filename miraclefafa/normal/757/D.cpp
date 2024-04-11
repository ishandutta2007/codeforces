#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <unordered_map>
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

void upd(int &a,int b) { a+=b; if (a>=mod) a-=mod;}
int n,cnt[(1<<20)+10],d[80][10];
char s[80];
int dp[(1<<20)+10][6],pd[(1<<20)+10][6];
int main() {
	scanf("%d",&n);
	scanf("%s",s);
	rep(i,0,n+1) {
		d[i][0]=0;
		rep(j,1,min(5,i)+1) {
			d[i][j]=d[i][j-1]+((s[i-j]-'0')<<(j-1));
		}
	}
	rep(i,0,n+1) {
		rep(j,0,(1<<20)) rep(k,0,6) pd[j][k]=dp[j][k],dp[j][k]=0;
		upd(pd[0][0],1);
		rep(S,0,(1<<20)) rep(k,0,6) if (pd[S][k]) {
			int r=pd[S][k],w=d[i][k];
			assert(w<=20);
			if (k!=0) upd(cnt[S|(1<<(w-1))],r);
			if (i==n) continue;
			if (k!=0) {
				if (s[i]=='0') upd(dp[S|(1<<(w-1))][0],r);
				else upd(dp[S|1<<(w-1)][1],r);
			}
			w=w*2+(s[i]-'0'); if (w>20) continue;
			if (w==0) upd(dp[S][0],r);
			else {
				assert(k+1<=5);
				upd(dp[S][k+1],r);
			}
		}
	}
	int ret=0;
	rep(i,1,21) upd(ret,cnt[(1<<i)-1]);
	printf("%d\n",ret);
}