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

char s[2048],t[512];int n,m;
int w[2048];
int dp[2048][2048];

int f(int k, int q){
	if(dp[k][q]>=0)return dp[k][q];
	int r;
	if(k==n)r=0;
	else {
		r=f(k+1,q);
		if(w[k]>=0&&w[k]-k-m<=q)r=max(r,1+f(w[k],q-(w[k]-k-m)));
	}
	return dp[k][q]=r;
}

int main(){
	scanf("%s%s",s,t);n=strlen(s);m=strlen(t);
	fore(i,0,n){
		int j,k;
		for(j=i,k=0;k<m&&j<n;++j){
			if(s[j]==t[k])k++;
		}
		w[i]=k==m?j:-1;
	}
	memset(dp,-1,sizeof(dp));
	fore(i,0,n+1)printf("%d%c",min(f(0,i),(n-i)/m)," \n"[i==n]);
	return 0;
}