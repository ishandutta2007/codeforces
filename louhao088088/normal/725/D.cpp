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
int n,m,ans,j;
struct node 
{
	int t,w,id;
	bool operator < (const node &a)const{return a.w<w;};
}a[maxn];
bool cmp(node a,node b){if(a.t==b.t)return a.id<b.id;return a.t>b.t;}
priority_queue<node>q;
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i].t=read(),a[i].w=read(),a[i].id=i,a[i].w=a[i].w-a[i].t;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)	
	{
		if(a[i].id!=1)q.push(a[i]);
		else
		{
			j=i;ans=i;break;
		}
	}	int Ans=ans,s=a[j].t;//cout<<ans<<endl;
	while(!q.empty())
	{
		node p=q.top();q.pop();
		s=s-p.w-1;//cout<<p.t<<" "<<p.w<<" "<<s<<endl;
		if(s<0)break;Ans--;
		while(s<a[j+1].t&&j<n)Ans++,q.push(a[j+1]),j++;ans=min(ans,Ans);
	}
	cout<<ans;
	return 0;
}