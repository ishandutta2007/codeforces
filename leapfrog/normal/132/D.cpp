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
char ch[1000005],cp[1000005];int n,rs[1000005],ct,fg[1000005];
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	int s=0;for(int i=1;i<=n;i++)
	{
		int v=ch[n-i+1]^48;
		if(v) {if(s==1) rs[++ct]=i-2,fg[ct]=0;s+=s<=1;}
		else if(s==1) rs[++ct]=i+s-3,fg[ct]=1,s=0;
		else if(s==2) s=1;
	}
	if(s) rs[++ct]=n+s-2,fg[ct]=1;
	printf("%d\n",ct);for(int i=1;i<=ct;i++) printf("%c2^%d\n",fg[i]?'+':'-',rs[i]);
	return 0;
}