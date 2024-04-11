#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=1e6+5,M=34005;
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
int n,m,f[maxn],a[maxn],x,y,sz[maxn],ans;
vector<int>e[maxn];
struct node
{
	int x,y,w;
}b[maxn],c[maxn];
bool cmp(node a,node b){return a.w<b.w;}
bool cmp2(node a,node b){return a.w>b.w;}
int getf(int x){if(x==f[x])return x;return f[x]=getf(f[x]);}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++)x=read(),y=read(),b[i].x=x,b[i].y=y,b[i].w=max(a[x],a[y]),c[i].x=x,c[i].y=y,c[i].w=min(a[x],a[y]);
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	sort(b+1,b+n,cmp);
	for(int i=1;i<n;i++)
	{
		int x=getf(b[i].x),y=getf(b[i].y);
		ans+=b[i].w*sz[x]*sz[y];sz[x]+=sz[y];f[y]=x;
	}//cout<<ans<<endl;
	for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	sort(c+1,c+n,cmp2);
	for(int i=1;i<n;i++)
	{
		int x=getf(c[i].x),y=getf(c[i].y);
		ans-=c[i].w*sz[x]*sz[y];sz[x]+=sz[y];f[y]=x;
	//	cout<<c[i].w<<" "<<sz[x]<<endl;
	}cout<<ans;
 	return 0;
}


/*********************************************************************
    :louhao088
    : 2022-01-27 15:26
*********************************************************************/