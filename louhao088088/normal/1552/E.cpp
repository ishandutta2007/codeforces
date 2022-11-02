#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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
int n,m,a[maxn],g[maxn],s[maxn],flag[maxn];
vector<int>b[maxn];
vector<pair<int,pair<int,int> > >c;
pair<int,int>ans[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)
		a[i]=read(),b[a[i]].push_back(i);
	for(int i=1;i<=n;i++)
		for(int j=0;j<m-1;j++)c.push_back(mp(b[i][j+1],mp(b[i][j],i)));
	sort(c.begin() , c.end());int u=(n-1)/(m-1)+1;
	for(auto i:c)
	{
		if(flag[i.se.se])continue;int x=i.se.fi,y=i.fi,F=0;
		for(int j=x;j<=y;j++)
			if(s[j]>=u)F=1;
		if(!F)
		{
			ans[i.se.se].fi=x,ans[i.se.se].se=y;
			for(int j=x;j<=y;j++)s[j]++;flag[i.se.se]=1;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i].fi<<" "<<ans[i].se<<endl;
 	return 0;
}