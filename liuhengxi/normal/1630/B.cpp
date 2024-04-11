#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int tt,n,k,a[N],c[N];
int main()
{
	read(tt);
	while(tt--)
	{
		int x=0,y,pos=0;
		read(n,k);
		y=n;
		F(i,0,n+1)c[i]=0;
		F(i,0,n)++c[read(a[i])],--a[i];
		F(i,0,n)c[i+1]+=c[i];
		for(int i=0,j=0;i<n;++i)
		{
			while(j<n&&((c[j]-c[i])<<1)-n<k)++j;
			if(((c[j]-c[i])<<1)-n>=k)if(j-i<y-x)y=j,x=i;
		}
		printf("%d %d\n",x+1,y);
		F(i,0,k-1)
		{
			int sum=0,last=pos;
			for(;sum<1;++pos)sum+=a[pos]>=x&&a[pos]<y?1:-1;
			printf("%d %d\n",last+1,pos);
		}
		printf("%d %d\n",pos+1,n);
	}
	return 0;
}