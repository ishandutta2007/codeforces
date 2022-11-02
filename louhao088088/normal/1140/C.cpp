#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define int long long
const int maxn=3e5+5;
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
int n,m,sum,ans;
struct node
{
	int t,x;
	 bool operator < (const node &g)const{return x>g.x;}
}a[maxn];
bool cmp(node a,node b){return a.t>b.t;}
bool cmp2(node a,node b){return a.x>b.x;}
priority_queue<node>q;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i].t=read(),a[i].x=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)q.push(a[i]),sum+=a[i].t;
	ans=sum*q.top().x;//cout<<sum<<" "<<q.top().x<<endl; 
	for(int i=m+1;i<=n;i++)
	{
		if(q.top().x<a[i].x)sum-=q.top().t,q.pop(),sum+=a[i].t,q.push(a[i]),ans=max(ans,sum*q.top().x);
	}
	sort(a+1,a+n+1,cmp2);sum=0;
	for(int i=1;i<=m;i++)
		sum+=a[i].t,ans=max(ans,sum*a[i].x);
	cout<<ans;
 	return 0;
}