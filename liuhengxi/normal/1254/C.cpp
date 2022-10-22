#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],b[N],n1,n2,m1,m2,maxx,c[N],d[N],ans[N],cnt;
long long area[N];
bool cmp(int u,int v){return area[u]<area[v];}
int main()
{
	read(n);
	F(i,2,n)
	{
		int sign;
		printf("2 1 2 %d\n",i+1);
		fflush(stdout);
		read(sign);
		if(sign==-1)a[n1++]=i;
		else b[n2++]=i;
	}
	F(i,2,n)
	{
		printf("1 1 2 %d\n",i+1);
		fflush(stdout);
		read(area[i]);
	}
	ans[cnt++]=0;
	maxx=0;m1=m2=0;
	F(i,0,n1)if(area[a[i]]>area[maxx])maxx=a[i];
	++area[maxx];
	F(i,0,n1)
	{
		int sign;
		if(a[i]==maxx)
		{
			c[m1++]=a[i];
			continue;
		}
		printf("2 1 %d %d\n",maxx+1,a[i]+1);
		fflush(stdout);
		read(sign);
		if(sign==-1)c[m1++]=a[i];
		else d[m2++]=a[i];
	}
	sort(c,c+m1,cmp);sort(d,d+m2,cmp);
	F(i,0,m1)ans[cnt++]=c[i];for(int i=m2-1;~i;--i)ans[cnt++]=d[i];
	ans[cnt++]=1;
	maxx=0;m1=m2=0;
	F(i,0,n2)if(area[b[i]]>area[maxx])maxx=b[i];
	++area[maxx];
	F(i,0,n2)
	{
		int sign;
		if(b[i]==maxx)
		{
			c[m1++]=b[i];
			continue;
		}
		printf("2 1 %d %d\n",maxx+1,b[i]+1);
		fflush(stdout);
		read(sign);
		if(sign==-1)c[m1++]=b[i];
		else d[m2++]=b[i];
	}
	sort(c,c+m1,cmp);sort(d,d+m2,cmp);
	F(i,0,m1)ans[cnt++]=c[i];for(int i=m2-1;~i;--i)ans[cnt++]=d[i];
	printf("0 ");
	F(i,0,n)printf("%d ",ans[i]+1);
	printf("\n");
	fflush(stdout);
	return 0;
}