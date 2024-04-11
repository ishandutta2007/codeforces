#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define mp make_pair
#define fi first
#define se second
#define int long long
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
struct node
{
	int x,y;
}a[maxn];
int n,m,ans=0,l;
bool cmp(node a,node b){return a.x<b.x;}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i].x=read(),a[i].y=read();
	sort(a+1,a+n+1,cmp);l=a[1].x;ans=1;a[n+1].x=1e10;
	for(int i=2;i<=n;i++)
	{
		if(l<a[i].x-a[i].y)ans++,l=a[i].x;
		else if(a[i].x+a[i].y<a[i+1].x)l=a[i].x+a[i].y,ans++;
		else l=a[i].x;
	}cout<<ans<<endl;
 	return 0;
}