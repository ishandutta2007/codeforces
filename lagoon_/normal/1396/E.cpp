#include<bits/stdc++.h>
#define re register
int n,sz[200100];
long long k,num=0;
struct eg{int to;eg*nx,*ll;}e1[400100],*la[200100],*cnt=e1,e[600100],*cnt1=e+200010;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
inline void addE1(re int a,re int b)
{
	*++cnt1=(eg){b,e[a].nx,e+a};e[a].nx=cnt1;
}
int hv,hs[200100],ed[200100],fa[200100];
void dfs(re int a,re int fa)
{
	sz[a]=1;
	re bool bl=1;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)dfs(i->to,a),sz[a]+=sz[i->to],bl&=(sz[i->to]*2<=n);
	if(bl&&sz[a]*2>=n)hv=a;
}
bool bl[200100];
struct nd
{
	int no;
};
inline bool operator < (const nd&A,const nd&B){return sz[A.no]==sz[B.no]?A.no<B.no:sz[A.no]>sz[B.no];}
std::multiset<nd>to[200100];
int dfn[200100],ee[200100],dep[200100],ff[200100][20],tot;
void rdfs(re int a)
{
	sz[a]=1;num+=dep[a];dfn[a]=++tot;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa[a])
	{
		dep[i->to]=dep[a]+1;
		fa[i->to]=a;
		rdfs(i->to);
		sz[a]+=sz[i->to];
		to[a].insert((nd){i->to});
	}
	ee[a]=tot;
	if(to[a].empty())ed[a]=a;
	else ed[a]=ed[to[a].begin()->no];
}
int f[200100];
int qry(re int a)
{
	re int ans=0;
	for(;a;a-=a&-a)ans+=f[a];
	return ans;
}
void add(re int a,re int ad)
{
	for(;a<=n;a+=a&-a)f[a]+=ad;
}
int qsz(re int a)
{
	if(a==0)return 1<<30;
	return qry(ee[a])-qry(dfn[a]-1);
}
void rnw(re int a)
{
	re int x=fa[a];
	if(!x)return;
	to[x].erase((nd){a});
	sz[a]=qsz(a);
	to[x].insert((nd){a});
	hs[x]=to[x].begin()->no;
	ed[x]=ed[hs[x]];
}
void sol(re int a)
{
	re int nn=ed[a];
	for(;a&&a!=hv;)
	{
		re int xx=qsz(a),yy;
		for(re int i1=17;a&&i1>=0;i1--)if((yy=qsz(ff[a][i1]))<=xx*2)a=ff[a][i1],xx=yy;
		if(a==0||a==hv)return;
		ed[a]=nn;
		rnw(a);
		a=fa[a];
		nn=ed[a];
	}
}
int q1[1001000],q2[1001000],ta,qq[100100];
std::vector<int>vc[100100];
int tta;
inline bool cmp(re int a1,re int a2){return vc[a1].size()<vc[a2].size();}
void ddfs(re int a,re int fa)
{
	if(!bl[a])vc[tta].push_back(a);
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)ddfs(i->to,a);
}
int main()
{
	re int x,y;
	scanf("%d%lld",&n,&k);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addE(x,y);
	}
	dfs(1,0);
	rdfs(hv);
	sz[0]=1<<30;
	if(num<k||(num-k)%2){puts("NO");return 0;}
	for(re int i=1;i<=n;i++)add(i,1),ff[i][0]=fa[i];
	for(re int i1=1;(1<<i1)<=n;i1++)
		for(re int i=1;i<=n;i++)ff[i][i1]=ff[ff[i][i1-1]][i1-1];
	while(num>k)
	{
		if(bl[hv]){puts("NO");return 0;}
		x=ed[hv];y=fa[x];//printf("****%d %d %d\n",x,y,hv);
		if(num-k>=2*(dep[y]))
		{
			num-=2*(dep[y]);
			to[y].erase((nd){x});
			add(dfn[x],-1);
			re int x1;
			if(to[y].empty())x1=y;
			else x1=to[y].begin()->no;
			add(dfn[x1],-1);
			q1[++ta]=x;q2[ta]=x1;
			bl[x]=bl[x1]=1;
			if(fa[x1])
			{
				to[fa[x1]].erase((nd){x1});
				if(to[fa[x1]].empty())ed[fa[x1]]=fa[x1];
				else ed[fa[x1]]=ed[to[fa[x1]].begin()->no];
				sol(fa[x1]);
			}
		}
		else
		{
			while(num-k<2*(dep[y]))y=fa[y];
			bl[x]=1;bl[y]=1;
			num-=2*(dep[y]);
			q1[++ta]=x;q2[ta]=y;
		}
	}
	puts("YES");
	qq[tta=1]=1;
	vc[1].push_back(hv);
	for(re eg*i=la[hv];i;i=i->nx)
	{
		tta++;
		qq[tta]=tta;
		ddfs(i->to,hv);
	}
	std::make_heap(qq+1,qq+tta+1,cmp);
	while(ta<n/2)
	{
		x=qq[1];std::pop_heap(qq+1,qq+tta+1,cmp);
		y=qq[1];std::pop_heap(qq+1,qq+tta,cmp);
		q1[++ta]=*vc[x].rbegin();q2[ta]=*vc[y].rbegin();
		vc[x].pop_back();vc[y].pop_back();
		std::push_heap(qq+1,qq+tta,cmp);
		std::push_heap(qq+1,qq+tta+1,cmp);
	}
	for(re int i=1;i<=ta;i++)printf("%d %d\n",q1[i],q2[i]);
}