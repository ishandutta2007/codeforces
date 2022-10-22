#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=64,M=32;
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
int m,a[M],n,pre[M][N][N*M],mx,e[N],d[M];
bool g[N][N],done[N],used[N];
int main()
{
	F(i,0,N)e[i]=i*(i-1)>>1;
	memset(pre,-1,sizeof pre);
	read(m);
	F(i,0,m)read(a[i]);
	sort(a,a+m);
	n=(a[m-1]<<1)+1;
	mx=n*a[m-1];
	pre[0][0][0]=0;
	F(i,0,m)
	{
		F(j,i,n)F(k,0,mx+1-a[i])if(~pre[i][j][k]&&k+a[i]>=e[j+1])pre[i+1][j+1][k+a[i]]=0;
		F(j,i,n)F(k,0,mx+1-a[i])if(~pre[i+1][j][k]&&k+a[i]>=e[j+1])pre[i+1][j+1][k+a[i]]=1;
	}
	n=m;
	while(!~pre[m][n][e[n]])++n;
	printf("%d\n",n);
	for(int i=m,j=e[n],k=n;k;)
	{
		if(!pre[i][k][j])j-=d[--k]=a[--i];
		else j-=d[--k]=a[i-1];
	}
	F(_,0,n)
	{
		int u=-1;
		F(i,0,n)if(!done[i]&&(!~u||d[i]<d[u]))u=i;
		done[u]=true;
		F(j,0,n)used[j]=done[j];
		F(j,0,d[u])
		{
			int v=-1;
			F(k,0,n)if(!used[k]&&(!~v||d[k]<d[v]))v=k;
			used[v]=true;
			g[u][v]=true;
		}
		F(j,0,n)if(!used[j])g[j][u]=true,--d[j];
	}
	F(i,0,n)
	{
		F(j,0,n)putchar(g[i][j]?'1':'0');
		puts("");
	}
	return 0;
}