//sk
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
char c[200005],t[200005];int n,m,ls[26],l[200005],r[200005];
int main()
{
	scanf("%s%s",c+1,t+1),n=strlen(c+1),m=strlen(t+1);
	for(int i=1,j=1;i<=n;i++) {l[i]=ls[c[i]-'a'];if(j<=m&&t[j]==c[i]) ls[c[i]-'a']=l[i]=j++;}
	memset(ls,0,sizeof(ls));int fg=0;
	for(int i=n,j=m;i>=1;i--) {r[i]=ls[c[i]-'a'];if(j&&t[j]==c[i]) ls[c[i]-'a']=r[i]=j--;}
	// for(int i=1;i<=n;i++) printf("%d , %d\n",l[i],r[i]);
	for(int i=1;i<=n;i++) if(!l[i]||!r[i]||l[i]<r[i]) fg=1;
	if(fg) return puts("No"),0;else return puts("Yes"),0;
}