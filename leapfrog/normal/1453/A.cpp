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
int T,t[100005],n,m;
int main()
{
	for(read(T);T--;)
	{
		read(n),read(m),memset(t,0,sizeof(t));int cnt=0;
		for(int x;n--;) read(x),t[x]++;
		for(int y;m--;) read(y),t[y]++;
		for(int i=1;i<=100;i++) if(t[i]>1) cnt++;
		printf("%d\n",cnt);
	}
	return 0;
}