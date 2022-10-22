#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5;
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
int n,k=1,ans,tot;
bool on[N],ban[N];
inline int f(int x){return n-x-(n+x-1)/x+1;}
int main()
{
	read(n);
	F(i,1,n+1)if(f(i)>f(k))k=i;
	ans=f(k);
	F(i,0,n/k+1)ban[i*k]=true;
	while(tot<ans)
	{
		int cnt=0,x;
		printf("%d ",k);
		F(i,0,n)if(cnt<k&&!on[i]&&!ban[i])on[i]=true,printf("%d ",i+1),++cnt;
		puts("");
		fflush(stdout);
		--read(x);
		F(i,0,k)on[x]=false,(++x)%=n;
		F(i,tot=0,n)tot+=on[i];
	}
	puts("0");
	fflush(stdout);
	return 0;
}