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
const int N=100005;int n,cn,f=0,g=0,ls;char ch[N];
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);for(int i=1;i<=n;i++) cn+=ch[i]=='#'&&(ls=i);
	for(int i=1;i<=n;i++) if(ch[i]=='(') f++;else if(!f) return puts("-1"),0;else f--;
	for(int i=1;i<=n&&g>=0;i++) if(ch[i]=='(') g++;else if(i==ls) g-=f+1;else g--;
	if(g) return puts("-1"),0;else for(int i=1;i<cn;i++) puts("1");
	return printf("%d\n",f+1),0;
}