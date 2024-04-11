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
using namespace std;
typedef long long ll;

int n,m;
int g[32];
int dp[1<<22];

int f(int m){
	if(dp[m]>=0)return dp[m];
	int r=1<<12;dp[m]=1<<12;
	fore(i,0,n)if(m&(1<<i))r=min(r,1+f(m|g[i]));
	return dp[m]=r;
}

void gen(int m, bool p){
	if(f(m)==0)return;
	fore(i,0,n)if(m&(1<<i)&&f(m)==1+f(m|g[i])){
		if(p)printf("%d ",i+1);
		gen(m|g[i],true);
		break;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x]|=1<<y;
		g[y]|=1<<x;
	}
	if(m==n*(n-1)/2){
		puts("0");
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	dp[(1<<n)-1]=0;
	int r=1<<12;
	fore(i,0,n)r=min(r,f(1<<i));
	assert(r<(1<<12));
	printf("%d\n",r);
	fore(i,0,n)if(f(1<<i)==r){
		gen(1<<i,false);
		printf("%d\n",i+1);
		return 0;
	}
	return 0;
}