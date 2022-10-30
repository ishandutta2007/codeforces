//
#include<bits/stdc++.h>
using namespace std;typedef unsigned int ui;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
int T,a,b,c;
int main()
{
	for(read(T);T--;)
	{
		read(a),read(b),read(c);
		if((a+b+c)%9!=0) {puts("NO");continue;}
		if(min(a,min(b,c))<(a+b+c)/9) {puts("NO");continue;}
		puts("YES");
	}
	return 0;
}