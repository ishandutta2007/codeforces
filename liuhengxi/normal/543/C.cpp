#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=25,M=(1<<20)+5;
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
int n,m,a[N][N],f[M],p[N][26],q[N][26];
char s[N][N];
int main()
{
	memset(f,0x3f,sizeof f);
	read(n,m);
	F(i,0,n)scanf("%s",s[i]);
	F(i,0,n)F(j,0,m)read(a[i][j]);
	F(i,0,n)F(j,0,m)p[j][s[i][j]-'a']|=1<<i,q[j][s[i][j]-'a']=min(q[j][s[i][j]-'a'],-a[i][j]);
	F(i,0,n)F(j,0,m)q[j][s[i][j]-'a']+=a[i][j];
	F(i,0,n)F(j,0,m)a[i][j]=min(a[i][j],q[j][s[i][j]-'a']);
	f[0]=0;
	F(j,1,1<<n)F(k,0,n)if(j>>k&1)F(i,0,m)
	{
		f[j]=min(f[j],f[j^1<<k]+a[k][i]);
		f[j]=min(f[j],f[j&~p[i][s[k][i]-'a']]+q[i][s[k][i]-'a']);
	}
	printf("%d\n",f[(1<<n)-1]);
	return 0;
}