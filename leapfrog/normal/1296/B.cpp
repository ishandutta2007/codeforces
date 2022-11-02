#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T;long long x;
int main()
{
	for(read(T);T;T--)
	{
		read(x);long long res=0;
		while(x>9) {long long qwq=x/10*10,gg=x-x/10*10;res+=qwq,x=gg+x/10;}
		printf("%d\n",res+x);
	}
	return 0;
}