//
//
#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n;char c[200005];
int main()
{
	for(read(T);T--;)
	{
		read(n),scanf("%s",c+1);int qwq=0;
		for(int i=2;i<=n;i++) if(c[i]!=c[i-1]) qwq++;
		printf("%d\n",(n-qwq)>>1);
	}
	return 0;
}