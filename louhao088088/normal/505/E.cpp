// Problem: CF505E Mr. Kitayuta vs. Bamboos
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF505E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 2021-11-15 14:40:46
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define lowbit (x&-x)
#define int long long
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
int n,m,k,z,a[maxn],h[maxn],l,r,res=0,b[maxn];
struct node
{
	int t,id;
	bool operator < (const node &a)const{return t>a.t;}
	node (int a,int b):t(a),id(b){};
};
bool check(int x)
{
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
	{
		b[i]=0;
		if(x-a[i]*m<h[i])q.push(node((x)/a[i],i));
	}
	//cout<<x<<endl;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(q.empty())return true;
			node p=q.top();q.pop();
			if(p.t<i)return false;
			b[p.id]+=z;
			if(x+b[p.id]-a[p.id]*m<h[p.id]) q.push(node(((x+b[p.id])/a[p.id]),p.id));
		}
	}
	if(!q.empty())
	{
		while(!q.empty())q.pop();
		return false;
	}
	return true;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();k=read();z=read();
	for(int i=1;i<=n;i++)h[i]=read(),a[i]=read(),r=max(h[i]+a[i]*m,r);
	l=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid-1,res=mid;
		else l=mid+1;
		//cout<<l<<" "<<r<<endl;
	}
	cout<<res<<endl;
 	return 0;
}