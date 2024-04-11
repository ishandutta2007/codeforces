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

int dp[705][705][2],d;
int s[705];
char x[705];int n;

int f(int k, int q, int b){
	if(dp[k][q][b]>=0)return dp[k][q][b];
	int r=0;
	if(k==n)r=q==0;
	else if(b){
		if(x[k]>=d){
			if(q)r=f(k+1,q-1,true);
		}
		else r=f(k+1,q,true);
		r+=(1LL*min(d,1*x[k])*f(k+1,q,false))%MOD;r%=MOD;
		if(q){
			r+=(1LL*max(x[k]-d,0)*f(k+1,q-1,false))%MOD;
			r%=MOD;
		}
	}
	else {
		r=(1LL*(d)*f(k+1,q,false))%MOD;
		if(q){
			r+=(1LL*(10-d)*f(k+1,q-1,false))%MOD;
			r%=MOD;
		}
	}
	return dp[k][q][b]=r;
}

int main(){
	s[0]=1;
	fore(i,1,705)s[i]=(10LL*s[i-1]+1)%MOD;
	scanf("%s",x);n=strlen(x);
	fore(i,0,n)x[i]-='0';
	int r=0;
	fore(i,1,10){
		memset(dp,-1,sizeof(dp));
		d=i;
		fore(q,1,n+1){
			r+=(1LL*s[q-1]*f(0,q,true))%MOD;
			r%=MOD;
		}
	}
	printf("%d\n",r);
	return 0;
}