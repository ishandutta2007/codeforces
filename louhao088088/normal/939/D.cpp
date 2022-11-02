#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=1e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,f[35],ans;
char a[maxn],b[maxn],c1[maxn],c2[maxn];
int getf(int x){if(x!=f[x])f[x]=getf(f[x]);return f[x];}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(int i=1;i<=26;i++)f[i]=i;
	n=read();
	scanf("%s",a+1);scanf("%s",b+1);
	for(int i=1;i<=n;i++)
	{
		int u=getf(a[i]-'a'+1),v=getf(b[i]-'a'+1);
		if(u!=v)f[u]=v,c1[++ans]=u,c2[ans]=v;
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
		putchar(c1[i]+'a'-1),putchar(' '),putchar(c2[i]+'a'-1),puts("");
 	return 0;
}