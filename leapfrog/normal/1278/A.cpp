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
char s[1005],t[10005],tn[26];int n,m;
inline char chk(int l,int r)
{
	memset(tn,0,sizeof(tn));
	for(int i=l;i<=r;i++) tn[t[i]-'a']++;
	for(int i=1;i<=n;i++) tn[s[i]-'a']--;
	for(int i=0;i<26;i++) if(tn[i]) return 0;
	return 1;
}
inline void solve()
{
	scanf("%s%s",s+1,t+1),n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=m-n+1;i++) if(chk(i,i+n-1)) return puts("YES"),void();
	puts("NO");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}