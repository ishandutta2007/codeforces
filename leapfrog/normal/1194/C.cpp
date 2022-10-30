//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
char s[105],t[105],p[105],sl,tl,pl;int cn[26];
inline void solve()
{
	scanf("%s%s%s",s+1,t+1,p+1),memset(cn,0,sizeof(cn));
	sl=strlen(s+1),tl=strlen(t+1),pl=strlen(p+1);
	for(int i=1;i<=tl;i++) cn[t[i]-'a']++;
	for(int i=1;i<=sl;i++) cn[s[i]-'a']--;
	for(int i=1;i<=pl;i++) cn[p[i]-'a']--;
	for(int i=0;i<26;i++) if(cn[i]>0) return puts("NO"),void();
	int l=1;for(int i=1;i<=tl&&l<=sl;i++) if(s[l]==t[i]) l++;
	return puts(l==sl+1?"YES":"NO"),void();
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}