#include<bits/stdc++.h>
using namespace std;
static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define fi first
#define se second
const int maxn=2e6+5;
vector<int>t[maxn];
stack<pair<int,int>>st;
int n,m,k,f[maxn],d[maxn],l,r,res,sum=0,s[maxn],ans[maxn];
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
struct node 
{
	int u,v,w,id;
	bool operator < (const node &x)const{return w>x.w;}
}a[maxn],b[maxn];
priority_queue<node>q;
int getf(int x)
{
	while(x!=f[x])x=f[x];
	return x;
}
void ins(int rt,int l,int r,int L,int R,int num)
{
	if(l>R||r<L)return;
	if(l>=L&&r<=R){t[rt].push_back(num);return;}
	ins(ls,l,mid,L,R,num),ins(rs,mid+1,r,L,R,num);
}
void merge(int x,int y)
{
	if(x==y)return;
	//cout<<x<<" "<<y<<endl;
	if(d[x]>d[y])swap(x,y);
	st.push({x,d[x]==d[y]});
	d[y]+=(d[x]==d[y]);f[x]=y;sum-=(s[y]&1)+(s[x]&1);
	s[y]=s[y]+s[x];sum+=(s[y]&1);
}
void del()
{
	int x=st.top().fi,y=f[st.top().fi],z=st.top().se;
	d[y]-=z;sum-=s[y]&1;s[y]-=s[x];sum+=(s[y]&1)+(s[x]&1);
	f[x]=x;st.pop();
}
void solve(int rt,int l,int r)
{
	int F=0,g=st.size();
	//cout<<rt<<" "<<l<<" "<<r<<" "<<mid<<" "<<endl;
	for(auto i:t[rt])
	{
		int x=getf(a[i].u),y=getf(a[i].v);
		merge(x,y);res=max(res,a[i].w);
	}
	if(!F)
	{
		if(l==r)
		{
			int cnt=0;
			while(sum&&!q.empty())
			{
				node p=q.top();q.pop();
				if(p.id<=l)
					b[++cnt]=p,merge(getf(p.u),getf(p.v)),res=max(res,p.w);	
			}
			//cout<<sum<<" "<<res<<endl;
			if(!sum)
			{
				for(int i=1;i<=cnt;i++)
					ins(1,1,m,b[i].id,l-1,b[i].id);
				ans[l]=res;
			}
			else ans[l]=-1;
			
		}
		else solve(rs,mid+1,r),solve(ls,l,mid);
	}//cout<<st.size()<<" "<<s<<endl;
	while(st.size()>g)del();
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();sum=n;
	for(int i=1;i<=m;i++)
	{
		a[i].u=read(),a[i].v=read(),a[i].w=read(),a[i].id=i;q.push(a[i]);
	}
	for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
	solve(1,1,m);
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}