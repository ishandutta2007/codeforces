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

void Z(char *a,int *nt,int n) {
	nt[0]=n;
	for (int i=1,j=0,k=0;i<n;i+=k,j=max(0,j-k)) {
		for (;i+j<n&&a[j]==a[i+j];++j);
		for (nt[i]=j,k=1;k<=j&&nt[k]!=j-k;k++) nt[i+k]=min(nt[k],j-k);
	}
}
void Z_match(char *a,int *nt,int n,char *b,int *ex,int m) {
	for (int i=0,j=0,k=0;i<m;i+=k,j=max(0,j-k)) {
		for (;j<n && i+j<m&&a[j]==b[i+j];++j);
		for (ex[i]=j,k=1;k<=j&&k+nt[k]!=j;k++) ex[i+k]=min(nt[k],j-k);
	}
}

const int N=101000;
char s[N],t[N];
int n,m,s1[N],s2[N],dp[N],ans,nt[N],ex[N];
int main() {
	scanf("%s%s",s,t);
	n=strlen(s); m=strlen(t);
	Z(t,nt,m); Z_match(t,nt,m,s,ex,n);
	dp[0]=1; s1[0]=1; s2[0]=1;
	int prec=-1;
	rep(i,1,n+1) {
		if (i>=m&&ex[i-m]==m) prec=i-m;
		if (prec>=0) dp[i]=s2[prec];
		s1[i]=(s1[i-1]+dp[i])%mod;
		s2[i]=(s2[i-1]+s1[i])%mod;
		ans=(ans+dp[i])%mod;
	}
	printf("%d\n",ans);
}