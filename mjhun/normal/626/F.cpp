#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

int n,kk;
int x[256];
int f[256][1024];
int f2[256][1024];

int main(){
	scanf("%d%d",&n,&kk);
	fore(i,0,n)scanf("%d",x+i);
	sort(x,x+n);
	fore(k,0,kk+1)f[0][k]=f[1][k]=1;
	for(int i=n-2;i>=0;--i){
		for(int s=0;s<=n;++s){
			for(int k=0;k<=kk;++k){
				int r=0;
				if((x[i+1]-x[i])*(s+1)<=k)r+=f[s+1][k-(s+1)*(x[i+1]-x[i])],r%=MOD;
				if((x[i+1]-x[i])*s<=k)r+=(1LL*(s+1)*f[s][k-s*(x[i+1]-x[i])])%MOD,r%=MOD;
				if(s>0&&(x[i+1]-x[i])*(s-1)<=k)r+=(1LL*s*f[s-1][k-(s-1)*(x[i+1]-x[i])])%MOD,r%=MOD;
				f2[s][k]=r;
			}
		}
		memcpy(f,f2,sizeof(f));
	}
	printf("%d\n",f[0][kk]);
	return 0;
}