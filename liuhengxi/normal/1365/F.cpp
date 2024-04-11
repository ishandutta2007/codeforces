#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=500;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,a[N],b[N],v[2*N],c[2*N][2*N];
int main()
{
	read(t);
	while(t--)
	{
		bool ans=true;
		read(n);
		F(i,0,n)read(a[i]);
		F(i,0,n)read(b[i]);
		F(i,0,n)v[i]=a[i];
		F(i,0,n)v[i+n]=b[i];
		sort(v,v+2*n);
		F(i,0,n)a[i]=lower_bound(v,v+2*n,a[i])-v;
		F(i,0,n)b[i]=lower_bound(v,v+2*n,b[i])-v;
		F(i,0,n)c[a[i]][a[n-1-i]]=0;
		F(i,0,n)c[b[i]][b[n-1-i]]=0;
		F(i,0,n)++c[a[i]][a[n-1-i]];
		F(i,0,n)--c[b[i]][b[n-1-i]];
		if(n&1)ans=a[n/2]==b[n/2];
		F(i,0,n)ans=ans&&c[a[i]][a[n-1-i]]==0;
		F(i,0,n)ans=ans&&c[b[i]][b[n-1-i]]==0;
		puts(ans?"Yes":"No");
	}
	return 0;
}