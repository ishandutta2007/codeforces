#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505;
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
struct credit
{
	int a,b,k;
	bool operator<(credit v)const{return b>v.b;}
}c[N];
int n;
long long f[N][N],ans;
int main()
{
	F(i,0,read(n))read(c[i].a,c[i].b,c[i].k);
	sort(c,c+n);
	F(i,0,n)F(j,0,i+1)
	{
		f[i+1][j]=max(f[i+1][j],f[i][j]+max(c[i].a-(long long)c[i].b*c[i].k,0ll));
		f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+c[i].a-c[i].b*(long long)j);
	}
	F(i,0,n+1)ans=max(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}