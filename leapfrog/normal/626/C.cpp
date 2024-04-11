//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,m,sm1,sm2;
int main()
{
	read(n),read(m),sm1=n*2,sm2=m*3;
	for(;n>=3&&m>=2;n-=3,m-=2)
		if(sm1+2<=sm2+3) sm1+=2,n++;else sm2+=3,m++;
	return printf("%d\n",max(sm1,sm2)),0;
}