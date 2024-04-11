//Coded by Kamiyama_Shiki on 2021.11.19 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=500005;char s[N],t[N];int n,m,nx[N];
int main()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1),nx[1]=0;
	for(int i=2,k=0;i<=m;i++)
	{
		while(k&&t[i]!=t[k+1]) k=nx[k];
		nx[i]=(k+=t[i]==t[k+1]);
	}
	int c[2]={0,0};for(int i=1;i<=n;i++) c[s[i]^48]++;
	for(int i=1,j=1;i<=n;i++,j++)
	{
		if(t[j]=='1'&&!c[1]) putchar('0'),c[0]--;
		else if(t[j]=='0'&&!c[0]) putchar('1'),c[1]--;
		else putchar(t[j]),c[t[j]^48]--;
		if(j==m) j=nx[j];
	}return putchar('\n'),0;
}