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
char a[1000005],b[1000005],zkak1,zkak2;int n,m;
int main()
{
	scanf("%s%s",a+1,b+1),n=strlen(a+1),m=strlen(b+1);
	if(n!=m) return puts("NO"),0;else zkak1=zkak2=0;
	for(int i=1;i<=n;i++) zkak1|=a[i]^48,zkak2|=b[i]^48;
	return puts(zkak1^zkak2?"NO":"YES"),0;
}