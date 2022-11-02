//Coded by Kamiyama_Shiki on 2021.11.16 {{{
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
const int N=1005;char ch[N],vs[N];int n,K;
int main()
{
	read(K),scanf("%s",ch+1),n=strlen(ch+1);
	for(int l=1,r=n;l<=r;l++,r--)
	{
		if(ch[l]=='?'&&ch[r]=='?') continue;
		if(ch[l]=='?') ch[l]=ch[r];
		else if(ch[r]=='?') ch[r]=ch[l];
		else if(ch[l]!=ch[r]) return puts("IMPOSSIBLE"),0;
	}
	for(int i=1;i<=n;i++) if(ch[i]!='?') vs[ch[i]-'a']=1;
	int ps=K-1;while(ps>=0&&vs[ps]) ps--;
	for(int i=(n+1)/2;i>=1;i--) if(ch[i]=='?')
	{
		ch[n-i+1]=ch[i]=max(ps,0)+'a',vs[ps]=1;
		while(ps>=0&&vs[ps]) ps--;
	}
	if(ps>=0) return puts("IMPOSSIBLE"),0;
	return printf("%s\n",ch+1),0;
}