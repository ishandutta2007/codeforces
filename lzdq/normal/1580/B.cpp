#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,m,k,p;
int c[205][205];
int f[205][205],g[205][205];
int main(){
	//freopen("in4.txt","r",stdin);
	//freopen("in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=0; i<=n*2; i++){
		c[i][0]=1;
		for(int j=1; j<=i; j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	f[1][1]=f[0][0]=1;
	for(int i=2; i<=n; i++) f[i][1]=1ll*f[i-1][1]*i%p;
	m--;
	while(m--){
		memset(g,0,sizeof(g));
		for(int s1=0; s1<=n; s1++)
			for(int s2=0; s2+s1+m-5<n; s2++)
				for(int k1=0; k1<=s1; k1++)
					for(int k2=0; k2<=s2&&k1+k2<=k; k2++)
						g[s1+s2+1][k1+k2]=(g[s1+s2+1][k1+k2]+1ll*f[s1][k1]*f[s2][k2]%p*c[s1+s2][s1])%p;
		/*
		for(int i=1; i<=n; i++){
			g[i][0]=(c[i*2][i]-c[i*2][i-1]+p)%p;
			for(int j=1; j<=i; j++)
				g[i][0]=(g[i][0]-g[i][j]+p)%p;
		}
		*/
		g[0][0]=1;
		memcpy(f,g,sizeof(f));
		//for(int i=1; i<=n; i++) for(int j=0; j<=i; j++) if(f[i][j]) printf("%d %d f %d\n",i,j,f[i][j]); puts("");
	}
	printf("%d\n",f[n][k]);
	return 0;
}