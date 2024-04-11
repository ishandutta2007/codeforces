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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=5010;
int n,ans;
char s[N];
int nt[N],ex[N];
int dp[N][N];
void Z(char *a,int *nt,int n) {
	rep(i,0,n) nt[i]=0;
	nt[0]=n;
	for (int i=1,j=0,k=0;i<n;i+=k,j=max(0,j-k)) {
		for (;i+j<n&&a[j]==a[i+j];++j);
		for (nt[i]=j,k=1;k<=j&&nt[k]!=j-k;k++) nt[i+k]=min(nt[k],j-k);
	}
}
void Z_match(char *a,int *nt,int n,char *b,int *ex,int m) {
	rep(i,0,m) ex[i]=0;
	for (int i=0,j=0,k=0;i<m;i+=k,j=max(0,j-k)) {
		for (;j<n && i+j<m&&a[j]==b[i+j];++j);
		for (ex[i]=j,k=1;k<=j&&k+nt[k]!=j;k++) ex[i+k]=min(nt[k],j-k);
	}
}

int main() {
	scanf("%d",&n);
	scanf("%s",s);
	rep(i,0,n) dp[0][i]=1;
	rep(i,1,n) if (s[i]!='0') {
		Z(s+i,nt,n-i);
		Z_match(s+i,nt,n-i,s,ex,i);
		ll cur=0;
		rep(j,i,n) {
			int r=i-(j-i+1);
//			if (i==2&&j==3) printf("%d %d\n",r,ex[r]);
			if (r>=0&&((ex[r]+r==i)||(ex[r]+r<i&&s[ex[r]+r]>s[i+ex[r]]))) {
				dp[i][j]=cur;
				cur=(cur+dp[r][i-1]);
				if (cur>=mod) cur-=mod;
			} else {
				if (r>=0) cur=(cur+dp[r][i-1]);
				if (cur>=mod) cur-=mod;
				dp[i][j]=cur;
			}
//			printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	rep(i,0,n) {
		ans+=dp[i][n-1];
		if (ans>=mod) ans-=mod;
	}
	printf("%d\n",ans);
}