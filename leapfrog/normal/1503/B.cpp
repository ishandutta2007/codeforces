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
int n,an,bn;pair<int,int>a[100005],b[100005];
inline void out(pair<int,int>x,int w) {printf("%d %d %d\n",w,x.first,x.second),fflush(stdout);}
int main()
{
	read(n);for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if((i+j)&1) a[++an]=make_pair(i,j);else b[++bn]=make_pair(i,j);
	for(int i=1,c,at=1,bt=1;i<=n*n;i++)
	{
		read(c);if(c==2)
		{
			if(at<=an) out(a[at],1),at++;
			else out(b[bt],3),bt++;
		}
		else if(c==1)
		{
			if(bt<=bn) out(b[bt],2),bt++;
			else out(a[at],3),at++;
		}
		else
		{
			if(at<=an) out(a[at],1),at++;
			else out(b[bt],2),bt++;
		}
	}
	return 0;
}