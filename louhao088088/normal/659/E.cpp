#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=2e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
void print(int x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,x,y,ans,f[maxn],v[maxn],s[maxn];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void merge(int x,int y){if(x<y)swap(x,y);v[x]+=v[y];f[y]=x;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n+1;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();
		int xx=find(x),yy=find(y);
		if(xx==yy)v[xx]=1;
		else merge(xx,yy);
	}
	for(int i=1;i<=n;i++) 
	    if(find(i)==i&&!v[i])ans++;
	print(ans);
 	return 0;
}