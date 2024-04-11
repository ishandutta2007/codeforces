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
bool check(int n)
{
	for(int i=2;i*i<=n;++i)if(n%i==0)return false;
	return true;
}
int n;
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)return x=1,y=0,void();
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
int inv(int a)
{
	int x,y;
	exgcd(a,n,x,y);
	return (x%n+n)%n;
}
int main()
{
	read(n);
	if(n==1)return puts("YES\n1"),0;
	if(n==4)return puts("YES\n1\n3\n2\n4\n"),0;
	if(!check(n))return puts("NO"),0;
	else puts("YES");
	printf("%d\n",1);
	int last=1;
	F(i,2,n)printf("%d\n",(int)((long long)inv(last)*i%n)),last=i;
	printf("%d\n",n);
	return 0;
}