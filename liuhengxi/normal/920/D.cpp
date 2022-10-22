#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("NO"),0
using namespace std;
const int N=5005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,v,a[N],p[N],q[N],t[N],c=-1,d=-1;//0:other 1:sum%k=v c:first 0 d:first 1
long long sum;
int main()
{
	read(n);read(k);read(v);
	F(i,0,n)read(a[i]),sum+=a[i];
	F(i,1,k)p[i]=-1;
	p[0]=-2;
	F(i,0,n)F(j,0,k)if(~p[j]&&p[j]!=i&&!~p[(j+a[i])%k])
	{
		p[(j+a[i])%k]=i;
		q[(j+a[i])%k]=j;
	}
	if(!~p[v%k]||sum<v)fail;
	else puts("YES");
	for(int i=v%k;i;i=q[i])t[p[i]]=1;
	sum=0;
	F(i,0,n)if(t[i])sum+=a[i];
	F(i,0,n)if(!t[i]){c=i;break;}
	F(i,0,n)if(t[i]){d=i;break;}
	if(!~c)c=1;if(!~d)d=1;
	F(i,0,n)if(t[i]&&i!=d)printf("100000 %d %d\n",i+1,d+1);
	F(i,0,n)if(!t[i]&&i!=c)printf("100000 %d %d\n",i+1,c+1);
	if(sum<v)printf("%lld %d %d\n",(v-sum)/k,c+1,d+1);
	if(v<sum)printf("%lld %d %d\n",(sum-v)/k,d+1,c+1);
	return 0;
}