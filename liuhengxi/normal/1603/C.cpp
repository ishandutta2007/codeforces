#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=998244353;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int tt,n,a[N],p[N],c[N],m,q[N],d[N],k,ans;
int main()
{
	read(tt);
	while(tt--)
	{
		ans=0;
		read(n);
		F(i,0,n)read(a[i]);
		m=0;
		for(int i=n;~--i;)
		{
			k=0;
			q[k]=a[i];d[k++]=1;
			F(j,0,m)
			{
				int s=(a[i]+p[j]-1)/p[j];
				ans=int((ans+(s-1ll)*(i+1ll)%MOD*c[j])%MOD);
				q[k]=a[i]/s;d[k++]=c[j];
			}
			m=0;
			F(j,0,k)if(m&&p[m-1]==q[j])reduce(c[m-1]+=d[j]);
			else p[m]=q[j],c[m++]=d[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}