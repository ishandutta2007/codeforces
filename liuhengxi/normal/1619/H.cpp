#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int c(int *p,int k,int x)
{
	while(k--)x=p[x];
	return x;
}
int n,q,k,p[N],p_[N],p_k[N],pk[N];
int main()
{
	read(n,q);while(k*k<n)++k;
	F(i,0,n)p_[--read(p[i])]=p_k[i]=pk[i]=i;
	F(i,0,n)F(j,0,k)pk[i]=p[pk[i]];
	F(i,0,n)F(j,0,k)p_k[i]=p_[p_k[i]];
	while(q--)
	{
		int op;read(op);
		if(op==1)
		{
			int x,y;--read(x),--read(y);
			swap(p[x],p[y]);p_[p[x]]=x;p_[p[y]]=y;
			int t1=c(p_,k,x),t2=c(p,k,x),t3=c(p_,k,y),t4=c(p,k,y);
			for(int i=0,u=x,v=t1;i<=k;++i,u=p[u],v=p[v])pk[v]=u;
			for(int i=0,u=x,v=t2;i<=k;++i,u=p_[u],v=p_[v])p_k[v]=u;
			for(int i=0,u=y,v=t3;i<=k;++i,u=p[u],v=p[v])pk[v]=u;
			for(int i=0,u=y,v=t4;i<=k;++i,u=p_[u],v=p_[v])p_k[v]=u;
		}
		if(op==2)
		{
			int u,t;--read(u);read(t);
			while(t>=k)t-=k,u=pk[u];
			while(t)--t,u=p[u];
			printf("%d\n",u+1);
		}
	}
	return 0;
}