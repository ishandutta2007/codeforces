//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int pr[1000005],pc,s[1000005];char pv[1000005];
int main()
{
	pv[1]=1;for(int i=1;i<=1000000;i++)
	{
		if(!pv[i]) pr[++pc]=i,s[i]=1;
		for(int j=1;j<=pc&&i*pr[j]<=1000000;j++) {pv[i*pr[j]]=1;if(i%pr[j]==0) break;}
	}
	for(int i=1;i<=1000000;i++) s[i]=s[i-1]+s[i];
	int Ca,x;for(read(Ca);Ca--;) read(x),printf("%d\n",s[x]-s[(int)sqrt(x)]+1);
	return 0;
}