#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<14)+5;
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
int n,m,ans;
char s[N>>2];
bool a[N],b[N];
short f[N],g[N],c[N];
short find(short *f,short x){return f[x]==x?x:f[x]=find(f,f[x]);}
int main()
{
	read(n,m);
	F(i,0,m)g[i]=i;
	F(i,0,n+1)
	{
		if(i!=n)scanf("%s",s);
		else F(j,0,m>>2)s[j]='0';
		F(j,0,m>>2)
		{
			if(s[j]>='A')s[j]-=7;
			a[j<<2|0]=s[j]>>3&1;
			a[j<<2|1]=s[j]>>2&1;
			a[j<<2|2]=s[j]>>1&1;
			a[j<<2|3]=s[j]>>0&1;
		}
		F(j,0,m)f[j]=j;
		F(j,1,m)if(a[j]&&a[j-1])f[find(f,j)]=find(f,j-1);
		F(j,0,m)if(a[j]&&b[j])c[find(g,j)]=find(f,j);
		F(j,0,m)if(a[j]&&b[j])f[find(f,j)]=find(f,c[find(g,j)]);
		F(j,0,m)if(b[j]&&find(g,j)==j&&!~c[j])++ans;
		F(j,0,m)b[j]=a[j],c[j]=-1,g[j]=f[j];
	}
	printf("%d\n",ans);
	return 0;
}