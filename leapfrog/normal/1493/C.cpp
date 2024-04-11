//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int T,n,K,a[100005][26],b[100005];char s[100005];
inline void solve()
{
	char tag=0;read(n),read(K),scanf("%s",s+1);
	if(n%K) return puts("-1"),void();
	for(int i=1;i<=n;a[i][s[i]-'a']++,i++) for(int j=0;j<26;j++) a[i][j]=a[i-1][j];
	for(int i=n;~i&&!tag;i--)
	{
		int gg=0;for(int j=0;j<26;j++) b[j]=(K-a[i][j]%K)%K,gg+=b[j];
		if(i==n&&gg==0)
		{
			for(int i=1;i<=n;i++) putchar(s[i]);
			putchar('\n'),tag=1;
		}
		if(gg>n-i) continue;
		for(char c=s[i+1]+1;c<='z'&&!tag;c++)
		{
			if(!b[c-'a']) b[c-'a']=K-1,gg+=K-1;else b[c-'a']--,gg--;
			if(gg>n-i-1) {gg-=K-1,b[c-'a']=0;continue;}
			while(gg+i+1<n) b[0]+=K,gg+=K;
			for(int j=1;j<=i;j++) putchar(s[j]);
			putchar(c);for(char h='a';h<='z';h++) for(int j=1;j<=b[h-'a'];j++) putchar(h);
			putchar('\n'),tag=1;
		}
	}
	if(!tag) puts("-1");
}
int main() {for(read(T);T--;) solve();return 0;}