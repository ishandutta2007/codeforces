#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=1e6+5;
int n,m,ans,x;

//bool cmp(node a,node b){if(a.t==b.t)return a.id<b.id;return a.t>b.t;}
int getf(int x,int y)
{
	int w=x/y,z=x%y,res=0;
	for(int i=1;i<=z;i++)res=res+(w+1)*(w+1);
	for(int i=z+1;i<=y;i++)res=res+w*w;return res;
}
struct node 
{
	int x,y;
	bool operator < (const node &a)const{return getf(a.x,a.y)-getf(a.x,a.y+1)>getf(x,y)-getf(x,y+1);};
}a[maxn];
priority_queue<node>q;
signed main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)x=read(),q.push({x,1}),ans+=x*x;//cout<<ans<<endl;
	for(int i=n+1;i<=m;i++)
	{
		node p=q.top();q.pop();//cout<<p.x<<" "<<p.y<<" "<<getf(p.x,p.y+1)<<" "<<getf(p.x,p.y)<<" "<<getf(5,2)<<endl;
		ans=ans+getf(p.x,p.y+1)-getf(p.x,p.y);q.push({p.x,p.y+1});
	}
	//for(int i=1;i<=m;i++)cout<<q.top()<<endl,ans+=q.top()*q.top(),q.pop();cout<<ans<<endl;
	cout<<ans<<endl;
	return 0;
}