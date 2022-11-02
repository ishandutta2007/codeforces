//{{{
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
int n,id[5005];char ch[5005][5005];
int main()
{
	read(n);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(ch[i][j]=='1'&&(!id[i]||ch[j][id[i]]=='1')) id[i]=j;
	for(int i=1;i<=n;i++) if(id[i]) for(int j=1;j<=n;j++) if(ch[id[i]][j]=='1'&&ch[j][i]=='1') return printf("%d %d %d\n",i,id[i],j),0;
	return puts("-1"),0;
}