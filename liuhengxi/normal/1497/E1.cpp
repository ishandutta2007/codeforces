#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,V=1e7+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct count
{
	int c[V],ans;
	void add(int x){ans+=!!c[x]++;}
	void del(int x){ans-=!!--c[x];}
}c;
int t,n,k,a[N],pre[N][22],f[N][22];
int delsqr(int x)
{
	for(int i=2,j=4;j<=x;j+=i,j+=++i)while(x%j==0)x/=j;
	return x;
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(k);
		F(i,0,n)read(a[i]),a[i]=delsqr(a[i]);
		F(j,0,k+1)
		{
			int l=0;
			F(i,0,n)
			{
				c.add(a[i]);
				while(l<=i&&c.ans>j)c.del(a[l++]);
				pre[i+1][j]=l;
			}
			while(l<n)c.del(a[l++]);
		}
		F(i,1,n+1)F(j,0,k+1)f[i][j]=n;
		F(i,1,n+1)F(j,0,k+1)F(l,0,j+1)f[i][j]=min(f[i][j],f[pre[i][l]][j-l]+1);
		printf("%d\n",f[n][k]);
	}
	return 0;
}