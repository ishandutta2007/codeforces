#include<cstdio>
#include<chrono>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<11)+5;
const int MOD1=1000000021,MOD2=1000000181;
inline int myrand()
{
	static int s1=1,s2=728272827;
	if((s1<<=1)>=MOD1)s1-=MOD1;
	if((s2<<=1)>=MOD2)s2-=MOD2;
	return s1^s2;
}
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,z[15],ind,val,ans[N];
#ifdef ONLINE_JUDGE
int query(int i,int j)
{
	int x;
	printf("? %d %d\n",i+1,j+1);
	fflush(stdout);
	return read(x);
}
#else
int p[N];
int query(int i,int j)
{
	return p[i]|p[j];
}
#endif
int query(int i)
{
	int a=(1<<m)-1;
	F(j,0,m)a=a&(i!=z[j]?query(i,z[j]):~(1<<j));
	return a;
}
int main()
{
	read(n);
#ifndef ONLINE_JUDGE
	F(i,0,n)read(p[i]);
#endif
	while((1<<m)<n)++m;
	F(i,0,m)z[i]=-1;
	while(true)
	{
		int i=myrand()%n,j=myrand()%n,x;
		bool c=true;
		if(i==j)continue;
		x=query(i,j);
		F(k,0,m)if((x>>k&1)==0)z[k]=i;
		F(k,0,m)c=c&&~z[k];
		if(c)break;
	}
	val=query(0);
	F(i,1,n)if(query(ind,i)==val)val=query(ind=i);
	F(i,0,n)if(i!=ind)ans[i]=query(ind,i);
	printf("! ");
	F(i,0,n)printf("%d ",ans[i]);
	puts("");
	fflush(stdout);
	return 0;
}