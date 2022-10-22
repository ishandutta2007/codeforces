#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=80,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct minion
{
	int a,b,id;
	bool operator<(minion y)const{return b<y.b;}
}m[N];
int t,n,k,f[N][N],p[N][N],last;
bool s[N];
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(k);
		F(i,0,n)read(m[i].a),read(m[i].b),m[i].id=i+1;
		sort(m,m+n);
		F(i,0,n+1)F(j,0,k+1)f[i][j]=-INF;
		f[0][0]=0;
		F(i,0,n)
		{
			F(j,0,k)
			{
				if(f[i][j]>f[i+1][j])
				{
					f[i+1][j]=f[i][j];
					p[i+1][j]=0;
				}
				if(f[i][j]+m[i].a-m[i].b*(k-j-1)>f[i+1][j+1])
				{
					f[i+1][j+1]=f[i][j]+m[i].a-m[i].b*(k-j-1);
					p[i+1][j+1]=1;
				}
			}
			if(f[i][k]>f[i+1][k])
			{
				f[i+1][k]=f[i][k];
				p[i+1][k]=0;
			}
		}
		F(i,0,n)s[i]=false;
		for(int i=n,j=k;i;--i)
		{
			if(p[i][j])
			{
				s[i-1]=true;
				--j;
			}
		}
		printf("%d\n",2*n-k);
		F(i,0,n)if(s[i])last=i;
		F(i,0,n)if(s[i]&&last!=i)printf("%d ",m[i].id);
		F(i,0,n)if(!s[i])printf("%d %d ",m[i].id,-m[i].id);
		printf("%d\n",m[last].id);
	}
	return 0;
}