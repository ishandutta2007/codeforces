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
int T,n,cn[5];
inline void solve()
{
	read(n),cn[0]=cn[1]=cn[2]=-n/3;int qwq=0;
	for(int i=1,x;i<=n;i++) read(x),cn[x%3]++;
	int res=0;for(int i=0;i<3;i++) qwq+=cn[i]>0;
	if(qwq==1)
	{
		if(cn[0]>0) res=-cn[1]-cn[2]*2;
		if(cn[1]>0) res=-cn[2]-cn[0]*2;
		if(cn[2]>0) res=-cn[0]-cn[1]*2;
	}
	else
	{
		if(cn[0]<0) res=cn[2]+cn[1]*2;
		if(cn[1]<0) res=cn[0]+cn[2]*2;
		if(cn[2]<0) res=cn[1]+cn[0]*2;
	}
	printf("%d\n",res);
}
int main() {for(read(T);T--;) solve();return 0;}