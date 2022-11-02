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
char ch[100005];int n;
int main()
{
	read(n),scanf("%s",ch+1);int cn0=0,cn1=0;
	for(int i=1;i<=n;i++) if(ch[i]=='0') cn0++;else cn1++;
	if(cn0^cn1) return printf("%d\n%s\n",1,ch+1),0;
	return printf("%d\n%c %s\n",2,ch[1],ch+2),0;
}