#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
char s[105],t[10005];int n,ps[105];
inline void solve()
{
	scanf("%s%s",s,t+1),n=strlen(t+1);
	for(int i=0;i<26;i++) ps[s[i]-'a']=i;
	int rs=0;for(int i=2;i<=n;i++) rs+=abs(ps[t[i]-'a']-ps[t[i-1]-'a']);
	printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}