//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int n,dep,r1[105],r2[105],r3[105],bs[105],vl[105];
inline void dfs(int x)
{
	if(x==dep&&vl[x]!=n) return;
	if(x==dep)
	{
		printf("%d\n",dep);
		for(int i=0;i<dep;i++) if(!~r2[i]) printf("lea e%cx, [%d*e%cx]\n",r1[i]+'a',bs[i],r3[i]+'a');
		else printf("lea e%cx, [e%cx + %d*e%cx]\n",r1[i]+'a',r2[i]+'a',bs[i],r3[i]+'a');
		exit(0);
	}
	for(int i=-1;i<=x;i++) for(int k=0;k<4;k++) for(int j=0;j<=x;j++)
	{
		if(~i) vl[x+1]=vl[i]+(1<<k)*vl[j];else vl[x+1]=(1<<k)*vl[j];
		r1[x]=x+1,r2[x]=i,r3[x]=j,bs[x]=1<<k,dfs(x+1);
	}
}
int main() {read(n),vl[0]=1;for(dep=0;;dep++) dfs(0);}