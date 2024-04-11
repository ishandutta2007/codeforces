#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
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
int a[N],x[N],y[N],m;
void opt(int u,int v)
{
	x[m]=u,y[m]=v;
	--a[u],--a[v];++a[v-u];++a[v+u];
	++m;
}
void solve(int c,int n)
{
	if(n<=2)return;
	int mid=1;
	while((mid<<1)<n)mid<<=1;
	if(n==(mid<<1))--n;
	int left=(mid<<1)-n;
	F(i,left,mid)opt(i<<c,((mid<<1)-i)<<c);
	solve(c+1,(n-left)>>1);
	solve(c,left-1);
}
int main()
{
	int tt;
	read(tt);
	while(tt--)
	{
    	int n,f=1;
    	read(n);
    	if(n==1)puts("1 0");
    	else if(n==2)puts("-1");
    	else
    	{
        	F(i,1,n+1)a[i]=1;
        	solve(0,n);
        	while(f<n)f<<=1;
        	F(i,1,f)if(!a[0]&&a[i]>=2){opt(i,i);break;}
        	F(i,1,f)
        	{
        		while(a[i])
        		{
        			if(a[i]==1)opt(0,i);
        			opt(i,i);
        		}
        	}
        	while(a[0])opt(0,f);
        	printf("%d\n",m);
        	F(i,0,m)printf("%d %d\n",x[i],y[i]);
        	a[f]=0;m=0;
    	}
	}
	return 0;
}