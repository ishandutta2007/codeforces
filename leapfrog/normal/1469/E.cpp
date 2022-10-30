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
int Ca,n,K,B,E;vector<int>v;char ch[1000005],fg[1048577];
inline void solve()
{
	read(n),read(K),scanf("%s",ch+1),v.clear();int cn=0;
	for(int i=1;i<=K-20;i++) if(ch[i]=='0') cn++;
	B=1,E=max(0,K-20);for(int i=1;i<=n-K+1;i++)
	{
		int tp=0;for(int j=max(i,i+K-20);j<=i+K-1;j++) tp=(tp<<1)|(49^ch[j]);
		v.push_back(tp);if(cn==0) fg[tp]=1;
		E++;if(ch[B]=='0') cn--;
		B++;if(ch[E]=='0') cn++;
	}
	for(int i=0;i<=n-K+1;i++) if(!fg[i])
	{
		string res;int x=i;
		while(x) res=char(48|(x&1))+res,x>>=1;
		if((int)res.size()>K) {puts("NO");break;}
		puts("YES");for(int i=res.size();i<K;i++) putchar('0');
		cout<<res<<endl;break;
	}
	for(int i=0;i<(int)v.size();i++) fg[v[i]]=0;
}
int main() {for(read(Ca);Ca--;) solve();return 0;}