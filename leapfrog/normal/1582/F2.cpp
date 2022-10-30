//Coded by STUPID_JUSTlN {{{
//Gened on 2021.10.24 18:05:02
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int n,a[1000005],go[5005][8195],cn[8195],rs[8195],rst;
char dp[8195][5005],v[5005][8195];// i  j
inline void adde(int i,int j) {go[i][++cn[i]]=j;}
int main()
{
	read(n),dp[0][0]=1;for(int i=1;i<=5000;i++) adde(i,i),v[i][i]=1;
	for(int k;n-->0;)
	{
		read(k);
		for(int i=1;i<=cn[k];i++)
		{
			int tw=go[k][i];dp[tw][k]=1;
			for(int j=k+1;j<=5000;j++) if(v[j][tw^j]) break;
				else v[j][tw^j]=1,adde(j,tw^j);
		}cn[k]=0;
	}
	for(int i=0;i<8192;i++) for(int j=0;j<=5000;j++) if(dp[i][j]) {rs[++rst]=i;break;}
	printf("%d\n",rst);for(int i=1;i<=rst;i++) printf("%d%c",rs[i],i==rst?'\n':' ');
	return 0;
}