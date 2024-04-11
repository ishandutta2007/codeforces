#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T>inline void write(T x) {{if(x<0) putchar('-'),x=-x;}{if(x>9) write(x/10);}putchar(x%10+48);}
int t,n,a[100005],c1,c2;
int main()
{
	for(read(t);t--;)
	{
		read(n),c1=0,c2=0;for(int i=1;i<=n;i++) scanf("%1d",a+i);
		for(int i=1;i<=n;i++,i++) c1+=!!(a[i]&1);
		for(int i=2;i<=n;i++,i++) c2+=!(a[i]&1);
		if(n&1) printf("%d\n",!c1+1);else printf("%d\n",!!c2+1);
	}
	return 0;
}