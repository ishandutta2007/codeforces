#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
char s[200005];int cn[200005];
inline void solve()
{
	scanf("%s",s+1);int n=strlen(s+1);
	for(int i=0;i<26;i++) cn[i]=0;
	for(int i=1;i<=n;i++) cn[s[i]-'a']++;
	int rs=0,c=0;for(int i=0;i<26;i++)
		if(cn[i]>1) rs++;else if(cn[i]) c++;
	printf("%d\n",rs+(c>>1));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}