//
//
#include<bits/stdc++.h>
using namespace std;const int P=1e9+7;
const int p[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int n,v[75],f[2][1<<20],t[75],pw[100005];
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	scanf("%d",&n),f[0][0]=1,pw[0]=1;int Z=0;
	for(int i=0;i<19;i++) v[p[i]]=i;
	for(int abc=1,x;abc<=n;abc++) scanf("%d",&x),t[x]++;
	for(int i=1;i<=100000;i++) pw[i]=(pw[i-1]<<1)%P;
	for(int abc=1;abc<=70;abc++)
	{
		int zz=0,x=abc;if(!t[abc]) continue;else Z^=1;
		for(int i=0;i<19;i++) while(x%p[i]==0) x/=p[i],zz^=(1<<i);
		for(int i=0;i<(1<<19);i++) f[Z][i]=(f[Z^1][i]+f[Z^1][i^zz])%P*1ll*pw[t[abc]-1]%P;
	}
	return printf("%d\n",f[Z][0]-1),0;
}