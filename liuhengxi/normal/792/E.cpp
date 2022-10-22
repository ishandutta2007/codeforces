#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,a[N],k;
long long ans=LLINF;
void check(int v)
{
	long long sum=0;
	if(v==0)return;
	F(i,0,n)
	{
		if(a[i]%v>a[i]/v)return;
		sum+=(a[i]+v)/(v+1);
	}
	if(sum<ans)ans=sum;
}
int main()
{
	F(i,0,read(n))read(a[i]);
	while(k*k<=a[0])++k;
	F(i,1,k)check(i);
	F(i,1,k)check(a[0]/i),a[0]%i==0&&(check(a[0]/i-1),1);
	printf("%lld\n",ans);
	return 0;
}