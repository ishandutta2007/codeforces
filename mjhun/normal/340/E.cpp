#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define MOD 1000000007
using namespace std;
typedef long long ll;

int n;
int a[2048];
int dp[2048][2048];

int f(int n, int k){
	if(dp[n][k]>=0)return dp[n][k];
	assert(k<=n);
	if(n==0)return dp[n][k]=1;
	int r=0;
	if(k){
		r=1LL*k*f(n-1,k-1)%MOD;
		if(n>k)r+=1LL*(n-k)*f(n-1,k)%MOD,r%=MOD;
	}
	else {
		if(n==1)r=0;
		else r=1LL*(n-1)*f(n-1,1)%MOD;
	}
	return dp[n][k]=r;
}

int main(){
	scanf("%d",&n);
	int k=0,m=0;
	fore(i,0,n)scanf("%d",a+i),a[i]--,m+=a[i]<0;
	fore(i,0,n)k+=a[i]>=0&&a[a[i]]<0;
	memset(dp,-1,sizeof(dp));
	printf("%d\n",f(m,k));
	return 0;
}