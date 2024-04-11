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
int Ca,n,a,b;char ch[1000005];
inline void solve()
{
	read(a),read(b),n=a+b,scanf("%s",ch+1);
	for(int i=1,j=n;i<j;i++,j--)
		if(ch[i]!='?'&&ch[j]!='?'&&ch[i]!=ch[j]) return puts("-1"),void();
		else if(ch[i]!='?') ch[j]=ch[i];else if(ch[j]!='?') ch[i]=ch[j];
	for(int i=1;i<=n;i++) if(ch[i]!='?') (ch[i]=='0'?a:b)--;
	if(a<0||b<0) return puts("-1"),void();
	for(int i=1,j=n;i<j;i++,j--) if(ch[i]=='?') {if(a>1) a-=2,ch[i]=ch[j]='0';else b-=2,ch[i]=ch[j]='1';}
	if((n&1)&&ch[(n+1)>>1]=='?') {if(a) a--,ch[(n+1)>>1]='0';else b--,ch[(n+1)>>1]='1';}
	if(a||b) return puts("-1"),void();else printf("%s\n",ch+1);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}