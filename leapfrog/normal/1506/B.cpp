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
int Ca,n,K,res=0,fs,ls;char ch[55];
inline void work(int wh)
{
	res++,ch[wh]='x';
	int mx=wh+K;if(mx>ls) return;
	while(ch[mx]=='.') mx--;
	work(mx);
}
inline void solve()
{
	read(n),read(K),scanf("%s",ch+1),res=0,ch[0]='*';
	fs=1;while(ch[fs]=='.') fs++;
	ls=n;while(ch[ls]=='.') ls--;
	if(fs==ls) return puts("1"),void();
	work(fs),res+=ch[ls]=='*',printf("%d\n",res);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}