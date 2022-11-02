#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int maxn=1e5+5,M=8196;
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
int n,m,r[maxn],x,sum,ans[maxn];
vector<int>a[maxn];
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=0;i<M;i++)a[i].push_back(0),r[i]=8195;r[0]=0;ans[0]=1;
	for(int i=1;i<=n;i++)
	{
		x=read();
		for(auto j:a[x])
		{
			int v=j^x;ans[v]=1;//cout<<x<<" "<<v<<" "<<j<<" "<<r[v]<<endl;
			while(r[v]>x)a[r[v]].push_back(v),r[v]--;
		}a[x].clear();
	}
	for(int i=0;i<M;i++)sum+=ans[i];cout<<sum<<endl;
	for(int i=0;i<M;i++)if(ans[i])cout<<i<<" ";cout<<endl;
 	return 0;
}