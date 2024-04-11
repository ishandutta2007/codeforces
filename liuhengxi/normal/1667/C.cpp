#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
int n;
int main()
{
	read(n);
	if(n==1)return puts("1\n1 1"),0;
	printf("%d\n",(n*2+1)/3);
	for(;n%3!=2;--n)printf("%d %d\n",n,n);
	int k=n/3;
	F(i,0,k+1)printf("%d %d\n",i+1,k-i+1);
	F(i,0,k)printf("%d %d\n",n-k+1+i,n-i);
	return 0;
}