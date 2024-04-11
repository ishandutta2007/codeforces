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

int inv(int a){
	int e=MOD-2,r=1;
	while(e){
		if(e&1)r=(1LL*r*a%MOD);
		e>>=1;
		a=(1LL*a*a)%MOD;
	}
	return r;
}

int dp[1024][1024];
int k,pa,pb,asd;

int f(int k, int a){
	if(dp[k][a]>=0)return dp[k][a];
	int r;
	if(k==0)r=0;
	else if(a>=k)r=(a+asd)%MOD;
	else {
		r=1LL*pb*((a+f(max(k-a,0),a))%MOD)%MOD;
		r+=1LL*pa*f(k,a+1)%MOD;
		r%=MOD;
	}
	return dp[k][a]=r;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&k,&pa,&pb);
	int s=pa+pb;
	pa=(1LL*pa*inv(s))%MOD;
	pb=(1LL*pb*inv(s))%MOD;
	assert((pa+pb)%MOD==1);
	asd=1LL*pa*inv(pb)%MOD;
	printf("%d\n",f(k,1));
	return 0;
}