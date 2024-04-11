#include<cstdio>
#include<bitset>
#include<algorithm>
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
int n,k,p[N],c[N],two;
bool vis[N];
bitset<N> f;
int main()
{
	read(n,k);
	F(i,0,n)--read(p[i]);
	F(i,0,n)if(!vis[i])
	{
		int len=1;
		for(int j=p[i];j!=i;j=p[j])vis[j]=true,++len;
		++c[len];
	}
	F(i,1,n+1)two+=c[i]*(i>>1);
	F(i,1,n+1)if(c[i]>2){int delta=(c[i]-1)>>1;c[i<<1]+=delta;c[i]-=delta<<1;}
	f[0]=1;
	F(i,1,n+1)while(c[i]--)f|=f<<i;
	printf("%d %d\n",k+!f[k],k>two?min(k+two,n):(k<<1));
	return 0;
}