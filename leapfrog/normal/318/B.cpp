//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,v1[1000005],v2[1000005];char c[1000005];
int main()
{
	scanf("%s",c+1),n=strlen(c+1);long long ans=0,tot=0;
	for(int i=1;i<=n-4;i++) if(c[i]=='h'&&c[i+1]=='e'&&c[i+2]=='a'&&c[i+3]=='v'&&c[i+4]=='y') v1[i]=1;
	for(int i=1;i<=n-4;i++) if(c[i]=='m'&&c[i+1]=='e'&&c[i+2]=='t'&&c[i+3]=='a'&&c[i+4]=='l') v2[i]=1;
	for(int i=1;i<=n;i++) if(v2[i]) ans+=tot;else if(v1[i]) ++tot;
	return printf("%lld\n",ans),0;
}