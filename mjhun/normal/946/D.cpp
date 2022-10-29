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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n,m,k;
char s[512];
int g[512][512];
int dp[512][512];

int f(int i, int k){
	int& r=dp[i][k];
	if(r>=0)return r;
	if(i==n)r=0;
	else {
		r=1<<30;
		fore(j,0,k+1)r=min(r,g[i][j]+f(i+1,k-j));
	}
	return r;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,n){
		scanf("%s",s);
		vector<int> x;
		fore(j,0,m)if(s[j]=='1')x.pb(j);
		fore(k,0,SZ(x)){
			g[i][k]=1<<30;
			fore(j,0,k+1)g[i][k]=min(g[i][k],x[SZ(x)-1-(k-j)]-x[j]+1);
		}
	}
	mset(dp,-1);
	printf("%d\n",f(0,k));
	return 0;
}