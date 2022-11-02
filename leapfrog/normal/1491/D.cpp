//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Q,a[55],b[55];
int main()
{
	for(read(Q);Q--;)
	{
		int x,y;read(x),read(y);char fg=0;
		if(x>y) {puts("NO");continue;}
		for(int i=0;i<30;i++) a[i]=(x>>i)&1,b[i]=(y>>i)&1;
		for(int i=1;i<30;i++) a[i]+=a[i-1],b[i]+=b[i-1];
		for(int i=0;i<30;i++) fg|=b[i]>a[i];
		puts(fg?"NO":"YES");
	}
	return 0;
}