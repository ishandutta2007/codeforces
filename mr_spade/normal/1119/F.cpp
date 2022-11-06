#include<cstdio>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<queue>
#define int long long
using std::max;
using std::min;
using std::vector;
using std::unordered_set;
using std::queue;
inline int read()
{
	int res=0,ch;
	while((ch=getchar())<'0'||ch>'9');
	for(;ch>='0'&&ch<='9';ch=getchar())
		res=res*10+ch-'0';
	return res;
}
inline void write(int x)
{
	if(x>=10)
		write(x/10);
	putchar(x%10+'0');
	return;
}
//const int M=1.05e7+5;
//int tot;
//int wsum[M];
//signed sum[M],ch[M][2];
//queue<signed> Q;
//inline void push_up(signed x)
//{
//	sum[x]=sum[ch[x][0]]+sum[ch[x][1]];
//	wsum[x]=wsum[ch[x][0]]+wsum[ch[x][1]];
//	return;
//}
//int xtr;
//void insert(signed &x,int lp,int rp,int pos,int k)
//{
//	if(!x)
//	{
//		xtr=max(xtr,(int)Q.size());
//		if(!Q.empty())
//			x=Q.front(),Q.pop();
//		else
//			x=++tot;
//	}
//	if(lp==rp)
//		return sum[x]+=k,wsum[x]+=lp*k,void();
//	int mid=(lp+rp)>>1;
//	if(pos<=mid)
//		insert(ch[x][0],lp,mid,pos,k);
//	else
//		insert(ch[x][1],mid+1,rp,pos,k);
//	push_up(x);
//	if(sum[x]==0&&wsum[x]==0)
//		Q.push(x),x=0;
//	return;
//}
//int select(signed x,int lp,int rp,int k)
//{
//	if(!k)
//		return 0;
//	if(lp==rp)
//		return lp*k;
//	int mid=(lp+rp)>>1;
//	if(sum[ch[x][0]]>=k)
//		return select(ch[x][0],lp,mid,k);
//	else
//		return wsum[ch[x][0]]+select(ch[x][1],mid+1,rp,k-sum[ch[x][0]]);
//}
inline int Mr_rand()
{
	static int x=1984;
	return x^=x<<13,x^=x>>17,x^=x<<7,x;
}
const int M=2e6+5;
int idx,tot;
int	key[M],prio[M],sum[M],size[M];
int p[M],ch[M][2];
queue<int> Q;
inline int which(int x)
{
	return ch[p[x]][1]==x;
}
inline void push_up(int x)
{
	sum[x]=sum[ch[x][0]]+(key[x]>>32)+sum[ch[x][1]];
	size[x]=size[ch[x][0]]+1+size[ch[x][1]];
	return;
}
inline int new_node(int k)
{
	int x;
	if(!Q.empty())
		x=Q.front(),Q.pop();
	else
		x=++tot;
	idx++;key[x]=k<<32|idx;prio[x]=Mr_rand();sum[x]=k;size[x]=1;
	p[x]=ch[x][0]=ch[x][1]=0;
	return x;
}
inline void rotate(int &r,int x)
{
	int y=p[x],f=which(x);
	ch[x][f^1]?p[ch[x][f^1]]=y:0;ch[y][f]=ch[x][f^1];
	p[x]=p[y];p[y]?ch[p[y]][which(y)]=x:r=x;
	p[y]=x;ch[x][f^1]=y;push_up(y);push_up(x);
	return;
}
inline void insert(int &r,int k)
{
	if(!r)
		return r=new_node(k),void();
	int x=new_node(k),y=r;
	while(ch[y][key[y]<key[x]])
		size[y]++,sum[y]+=k,y=ch[y][key[y]<key[x]];
	size[y]++;sum[y]+=k;ch[y][key[y]<key[x]]=x;p[x]=y;
	while(p[x]&&prio[x]<prio[p[x]])
		rotate(r,x);
	return;
}
inline void erase(int &r,int k)
{
	int x,y=r;
	while((key[y]>>32)!=k)
		y=ch[y][(key[y]>>32)<k];
	while(ch[y][0]||ch[y][1])
		if(!ch[y][1]||(ch[y][0]&&prio[ch[y][0]]<prio[ch[y][1]]))
			rotate(r,ch[y][0]);
		else
			rotate(r,ch[y][1]);
	Q.push(y);
	if(r==y)
		return r=0,void();
	ch[p[y]][which(y)]=0;
	for(x=p[y];x;x=p[x])
		size[x]--,sum[x]-=k;
	return;
}
//void split(int z,int &x,int &y,int k)
//{
//	if(!z)
//		return x=y=0,void();
//	if(key[z]<=k)
//		x=z,split(ch[z][1],ch[z][1],y,k);
//	else
//		y=z,split(ch[z][0],x,ch[z][0],k);
//	push_up(z);
//	return;
//}
//int merge(int x,int y)
//{
//	if(!x||!y)
//		return x^y;
//	if(prio[x]<prio[y])
//		return ch[x][1]=merge(ch[x][1],y),push_up(x),x;
//	else
//		return ch[y][0]=merge(x,ch[y][0]),push_up(y),y;
//}
//inline void insert(int &r,int k)
//{
//	int dx,dy;
//	split(r,dx,dy,k<<32);
//	r=merge(merge(dx,new_node(k)),dy);
//	return;
//}
//inline void erase(int &r,int k)
//{
//	int dx,dy,dz,dw;
//	split(r,dx,dy,k<<32);
//	split(dy,dz,dw,(k+1)<<32);
//	Q.push(dz);dz=merge(ch[dz][0],ch[dz][1]);
//	r=merge(dx,merge(dz,dw));
//	return;
//}
inline int select(int r,int k)
{
	int res=0,x=r;
	while(x)
		if(size[ch[x][0]]+1>k)
			x=ch[x][0];
		else
			res+=sum[ch[x][0]]+(key[x]>>32),k-=size[ch[x][0]]+1,x=ch[x][1];
	return res;
}
const int N=2.5e5+5;
int n;
signed dis[N];
bool book[N];
unordered_set<int> rt;
int r[N],deg[N];
struct cell
{
	int v,w;
};
vector<int> ta[N];
vector<cell> e[N],f[N];
int dp[N][2];
int ans[N];
inline int find(int x)
{
	return dis[x]==x?x:(dis[x]=find(dis[x]));
}
inline void uf_merge(int x,int y)
{
	if((x=find(x))==(y=find(y)))
		return;
	rt.erase(x);dis[x]=y;
	return;
}
void dfs(int x,int father,int fw,int w)
{
	int res=0;
	if(father!=0)
		erase(r[x],fw);
	for(cell y:f[x])
		if(y.v!=father)
		{
			dfs(y.v,x,y.w,w);
			erase(r[x],y.w);
			res+=dp[y.v][0];
			insert(r[x],dp[y.v][1]-dp[y.v][0]);
		}
	dp[x][1]=fw+res+select(r[x],max(deg[x]-(father!=0)-w,0ll));
	if(father==0||w>=1)
		dp[x][0]=min(dp[x][1],res+select(r[x],max(deg[x]-w,0ll)));
	else
		dp[x][0]=dp[x][1];
	for(cell y:f[x])
		if(y.v!=father)
		{
			erase(r[x],dp[y.v][1]-dp[y.v][0]);
			insert(r[x],y.w);
		}
	if(father!=0)
		insert(r[x],fw);
	return;
}
signed main()
{
// 	freopen("test.in","r",stdin);
// 	freopen("test.out","w",stdout);
	int x,y,z;
	register int i;
	n=read();
	for(i=1;i<=n-1;i++)
	{
		x=read();y=read();z=read();
		deg[x]++;deg[y]++;
		e[x].push_back(cell{y,z});
		e[y].push_back(cell{x,z});
		insert(r[x],z);
		insert(r[y],z);
	}
	for(i=1;i<=n;i++)
		ta[deg[i]-1].push_back(i);
	for(i=n-1;i>=0;i--)
	{
		for(int x:ta[i])
		{
			rt.insert(x);
			dis[x]=x;
			for(cell y:e[x])
				if(book[y.v])
				{
					f[x].push_back(cell{y.v,y.w});
					f[y.v].push_back(cell{x,y.w});
					uf_merge(x,y.v);
				}
			book[x]=1;
		}
		for(int x:rt)
			dfs(x,0,0,i),ans[i]+=dp[x][0];
	}
	for(i=0;i<n;i++)
		write(ans[i]),putchar(' ');
	putchar('\n');
//	fprintf(stderr,"%lld\n",xtr);
	return 0;
}