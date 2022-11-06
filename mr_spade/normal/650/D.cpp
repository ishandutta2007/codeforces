#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<algorithm>
#include<vector>
using std::max;
using std::lower_bound;
using std::sort;
using std::unique;
using std::vector;
inline int read()
{
	int res=0,f=0;
	char ch;
	while((ch=getchar())<'0'||ch>'9')
		f|=ch=='-';
	for(;ch>='0'&&ch<='9';ch=getchar())
		res=res*10+ch-'0';
	return f?-res:res;
}
inline void write(int x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>=10)
		write(x/10);
	putchar(x%10+'0');
	return;
}
const int N=4e5+5;
int n,m,q;
int len1[N],len2[N];
int h[N],r1[N],r2[N];
int ban[N];
struct cell
{
	int a,b;
}c[N];
int tot;
int Max[N*50],ch[N*50][2];
vector<int> V;
int modify(int x,int lp,int rp,int pos,int k)
{
	int y=++tot;
	if(lp==rp)
		return Max[y]=max(Max[x],k),y;
	int mid=(lp+rp)>>1;
	if(pos<=mid)
		ch[y][1]=ch[x][1],ch[y][0]=modify(ch[x][0],lp,mid,pos,k);
	else
		ch[y][0]=ch[x][0],ch[y][1]=modify(ch[x][1],mid+1,rp,pos,k);
	Max[y]=max(Max[ch[y][0]],Max[ch[y][1]]);
	return y;
}
int query(int x,int lp,int rp,int l,int r)
{
	if(!x||l>r)
		return 0;
	if(lp==l&&rp==r)
		return Max[x];
	int mid=(lp+rp)>>1;
	if(r<=mid)
		return query(ch[x][0],lp,mid,l,r);
	else if(l>=mid+1)
		return query(ch[x][1],mid+1,rp,l,r);
	else
		return max(query(ch[x][0],lp,mid,l,mid),query(ch[x][1],mid+1,rp,mid+1,r));
}
void solve(int l,int r,int w)
{
	if(l==r)
		return ban[l]=w,void();
	int mid=(l+r)>>1,res;
	register int i;
	res=w;
	for(i=l;i<=mid;i++)
		res=max(res,query(r2[r+1],1,m,h[i]+1,m)+len1[i]);
	solve(mid+1,r,res);
	res=w;
	for(i=mid+1;i<=r;i++)
		res=max(res,query(r1[l-1],1,m,1,h[i]-1)+len2[i]);
	solve(l,mid,res);
	return;
}
signed main()
{
	register int i;
	n=read();q=read();
	for(i=1;i<=n;i++)
		V.push_back(h[i]=read());
	for(i=1;i<=q;i++)
		c[i].a=read(),V.push_back(c[i].b=read());
	sort(V.begin(),V.end());
	m=unique(V.begin(),V.end())-V.begin();
	while((int)V.size()>m)
		V.pop_back();
	for(i=1;i<=n;i++)
		h[i]=lower_bound(V.begin(),V.end(),h[i])-V.begin()+1;
	for(i=1;i<=q;i++)
		c[i].b=lower_bound(V.begin(),V.end(),c[i].b)-V.begin()+1;
	Max[0]=0;
	for(i=1;i<=n;i++)
	{
		len1[i]=query(r1[i-1],1,m,1,h[i]-1)+1;
		r1[i]=modify(r1[i-1],1,m,h[i],len1[i]);
	}
	for(i=n;i>=1;i--)
	{
		len2[i]=query(r2[i+1],1,m,h[i]+1,m)+1;
		r2[i]=modify(r2[i+1],1,m,h[i],len2[i]);
	}
	solve(1,n,0);
	int res;
	for(i=1;i<=q;i++)
	{
		res=ban[c[i].a];
		res=max(res,query(r1[c[i].a-1],1,m,1,c[i].b-1)+1+query(r2[c[i].a+1],1,m,c[i].b+1,m));
		write(res);putchar('\n');
	}
	return 0;
}