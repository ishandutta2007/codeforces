//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
char ch[100005],tag[26];ll res=1;int n;
int main()
{
	scanf("%s",ch+1),n=strlen(ch+1);int cnt=0,cn=0;
	for(int i=1;i<=n;i++) if(i>1&&ch[i]=='?') cnt++;else if(ch[i]>='A'&&ch[i]<='J') tag[ch[i]-'A']=1;
	for(int i=0;i<10;i++) cn+=tag[i];
	for(int i=10-cn+1;i<=10;i++) res*=i;
	if(ch[1]>='A'&&ch[1]<='Z') res=res/10*9;else if(ch[1]=='?') res*=9;
	printf("%lld",res);while(cnt--) putchar('0');
	return putchar('\n'),0;
}