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
inline char chk(int a)
{
	for(int i=2;i<a;i++) if(a%i==0) return 0;
	return 1;
}
int n,tot;
int main()
{
	read(n);
	for(tot=n;;tot++) if(chk(tot)) break;
	write(tot),putchar('\n'),write(n),putchar(' '),write(1),putchar('\n'),tot--;
	for(int i=1;i<n;i++) write(i),putchar(' '),write(i+1),putchar('\n'),tot--;
	for(int zk=2,g=0;tot>0;zk++,zk+=((g&1)<<1),g++) write(zk-1),putchar(' '),write(zk+1),putchar('\n'),tot--;
	return 0;
}