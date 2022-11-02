#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
template<typename T>inline void write(T x) {{if(x<0) putchar('-'),x=-x;}{if(x>9) write(x/10);}putchar(x%10+48);}
int n,a[2005],s=0,r,tot;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),s+=a[i];
	r=a[1],tot=1;for(int i=2;i<=n;i++) if((a[1]>>1)>=a[i]) r+=a[i],tot++;
	if((r<<1)<=s) return puts("0"),0;else write(tot),putchar('\n');
	putchar('1');for(int i=2;i<=n;i++) if((a[1]>>1)>=a[i]) putchar(' '),write(i);
	return puts(""),0;
}