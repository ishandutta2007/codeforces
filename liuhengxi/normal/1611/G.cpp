#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,INF=0x3fffffff;
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
bool p1[N<<1];int p2[N<<1];
int tt,n,m,ans,l[N],r[N];
bool *s[N];int *d=p2+N;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,m);
		s[0]=p1;
		F(i,0,n+m-1)l[i]=n+m,r[i]=-n-m;
		F(i,0,n)F(j,0,m)l[i+j]=min(l[i+j],(i-j)>>1),r[i+j]=max(r[i+j],((i-j)>>1)+1);
		F(i,0,n+m-1)s[i+1]=s[i]+r[i]-l[i];
		F(i,0,n+m-1)s[i]-=l[i];
		F(i,0,n)F(j,0,m)
		{
			int c=getchar();while(c!='0'&&c!='1')c=getchar();
			if(c=='1')s[i+j][(i-j)>>1]=1;
		}
		ans=0;
		F(i,-n-m-2,n+m+2)d[i]=0;
		for(int i=0;i<n+m-1;i+=2)
		{
			int k=INF;
			d[l[i]]+=d[l[i]-1];
			F(j,l[i],r[i])
			{
				if(d[j])k=j;
				if(s[i][j])
				{
					if(k==INF)++d[k=j],++ans;
					if(k!=j)--d[k],++d[j],k=j;
				}
			}
		}
		F(i,-n-m-2,n+m+2)d[i]=0;
		for(int i=1;i<n+m-1;i+=2)
		{
			int k=INF;
			d[l[i]]+=d[l[i]-1];
			F(j,l[i],r[i])
			{
				if(d[j])k=j;
				if(s[i][j])
				{
					if(k==INF)++d[k=j],++ans;
					if(k!=j)--d[k],++d[j],k=j;
				}
			}
		}
		printf("%d\n",ans);
		memset(p1,0,sizeof(bool)*n*m);
	}
	return 0;
}