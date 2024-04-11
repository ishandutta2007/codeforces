#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int np=17;
int n;
int w[64];
int a[128];
int dp[128][1<<17];
int c[128][1<<17];

int f(int k, int m){
	if(dp[k][m]>=0)return dp[k][m];
	if(k==n)return dp[k][m]=0;
	int r=1<<25;
	fore(i,1,60){
		if(!(m&w[i])){
			int rr=abs(a[k]-i)+f(k+1,m|w[i]);
			if(rr<r){
				r=rr;
				c[k][m]=i;
			}
		}
	}
	return dp[k][m]=r;
}

int main(){
	fore(i,1,60){
		fore(j,0,np){
			if(i%p[j]==0)w[i]|=1<<j;
		}
	}
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	memset(dp,-1,sizeof(dp));
	f(0,0);
	int m=0;
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",c[i][m]);
		m|=w[c[i][m]];
	}
	puts("");
	return 0;
}