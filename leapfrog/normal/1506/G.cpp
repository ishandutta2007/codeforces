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
int Ca,n,ls[26],v[26];char ch[200005],st[200005];
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1);int tp=0;
	memset(ls,0,sizeof(ls)),memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++) ls[ch[i]-'a']=i;
	for(int i=1;i<=n;i++) if(!v[ch[i]-'a'])
	{
		while(tp&&ls[st[tp]-'a']>i&&ch[i]>st[tp]) v[st[tp--]-'a']=0;
		st[++tp]=ch[i],v[ch[i]-'a']=1;
	}
	for(int i=1;i<=tp;i++) putchar(st[i]);
	putchar('\n');
}
int main() {for(read(Ca);Ca--;) solve();return 0;}