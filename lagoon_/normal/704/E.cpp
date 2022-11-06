#include<bits/stdc++.h>
#define re register
#define IT std::multiset<par>::iterator
#define pc(a,b) ((a)<=(b)+eps&&(a)>=(b)-eps)
struct sut{int a,b,c;long double t;};
long double T,ans=1e233,eps=1e-10;
struct par{long double b;int k,no;};
struct ele{long double t;int no,tp;}pq[1001000];
bool operator < (const ele&A,const ele&B){return (A.t<B.t+eps&&A.t>B.t-eps)?(A.tp<B.tp):A.t>B.t;}
int ta,in[100100];
bool operator < (const par&A,const par&B){return A.k*T+A.b<B.k*T+B.b-eps;}
std::multiset<par>ss;
IT ita[100100];
void gans(std::vector<sut>&f)
{
	re int m=f.size();
	ss.clear();
	re IT it,it1;
	ta=0;
	for(re int i=0;i<m;i++)
	{//printf("**%d %d %d %.10Lf\n",f[i].a,f[i].b,f[i].c,f[i].t);
		in[i]=0;
		pq[++ta]=(ele){f[i].t,i,-1};
		pq[++ta]=(ele){f[i].t+(long double)abs(f[i].b-f[i].a)/f[i].c,i,-2};
	}
	std::make_heap(pq+1,pq+ta+1);
	while(ta)
	{
		ele x=pq[1];std::pop_heap(pq+1,pq+ta+1);ta--;
		T=x.t;
		if(x.tp==-1)
		{
			in[x.no]=1;
			if(f[x.no].a<=f[x.no].b)it=ss.insert((par){f[x.no].a-f[x.no].c*T,f[x.no].c,x.no});
			else it=ss.insert((par){f[x.no].a+f[x.no].c*T,-f[x.no].c,x.no});
			ita[x.no]=it;
			if(it!=ss.begin())
			{
				it1=it;it1--;if(it1->k>it->k)pq[++ta]=(ele){(it->b-it1->b)/(it1->k-it->k),it->no,it1->no},std::push_heap(pq+1,pq+ta+1);
				else if(pc(it->b+it->k*T,it1->b+it1->k*T))pq[++ta]=(ele){T,it->no,it1->no},std::push_heap(pq+1,pq+ta+1);
			}it1=it;it++;
			if(it!=ss.end()){
			if(it1->k>it->k)pq[++ta]=(ele){(it->b-it1->b)/(it1->k-it->k),it->no,it1->no},std::push_heap(pq+1,pq+ta+1);
				else if(pc(it->b+it->k*T,it1->b+it1->k*T))pq[++ta]=(ele){T,it->no,it1->no},std::push_heap(pq+1,pq+ta+1);}
		}else if(x.tp==-2)
		{
			in[x.no]=0;it=ita[x.no];
			it1=it;it1++;ss.erase(it);it=it1;
			if(it1!=ss.begin())
			{
				it1--;
				if(it!=ss.end()&&it1->k>it->k)pq[++ta]=(ele){(it->b-it1->b)/(it1->k-it->k),it->no,it1->no},std::push_heap(pq+1,pq+ta+1);
				else if(pc(it->b+it->k*T,it1->b+it1->k*T))pq[++ta]=(ele){T,it->no,it1->no},std::push_heap(pq+1,pq+ta+1);
			}
		}else
		{
			if(in[x.no]&&in[x.tp]){ans=std::min(ans,T);return;}
		}
	}
}
struct eg{int to;eg*nx;}e[200100],*la[100100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int top[100100],dep[100100],hv[100100],sz[100100],no[100100],fa[100100];
std::vector<sut>vc[100100];
void dfs(re int a)
{
	sz[a]=1;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa[a])
	{
		fa[i->to]=a;dep[i->to]=dep[a]+1;dfs(i->to);sz[a]+=sz[i->to];
		if(sz[hv[a]]<sz[i->to])hv[a]=i->to;
	}
}
void dfs1(re int a)
{
	if(hv[a])
	{
		no[hv[a]]=no[a]+1;top[hv[a]]=top[a];
		dfs1(hv[a]);
	}
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=hv[a]&&i->to!=fa[a])
	{
		no[i->to]=1;top[i->to]=i->to;dfs1(i->to);
	}
}
void upd(re int t,re int c,re int a,re int b)
{
	re long double t1=t,t2=t+(long double)(dep[a]+dep[b])/c;
	re int i1=a,i2=b;
	for(;top[i1]!=top[i2];i2=fa[top[i2]])if(dep[top[i1]]>dep[top[i2]])std::swap(i1,i2);
	if(dep[i1]>dep[i2])std::swap(i1,i2);t2-=(long double)2*dep[i1]/c;
	i1=a;i2=b;
	for(;top[i1]!=top[i2];)
	{
		if(dep[top[i1]]>dep[top[i2]])
		{
			vc[top[i1]].push_back((sut){no[i1],0,c,t1+(long double)dep[a]/c-(long double)dep[i1]/c});
			i1=fa[top[i1]];
		}
		else
		{
			vc[top[i2]].push_back((sut){0,no[i2],c,t2-(long double)dep[b]/c+(long double)dep[fa[top[i2]]]/c});
			i2=fa[top[i2]];
		}
	}
	vc[top[i1]].push_back((sut){no[i1],no[i2],c,t1+(long double)dep[a]/c-(long double)dep[i1]/c});
}
int main()
{
	re int n,m,x,y,t,c;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addE(x,y);
	}
	dfs(1);top[1]=no[1]=1;
	dfs1(1);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&t,&c,&x,&y);
		upd(t,c,x,y);
	}
	for(re int i=1;i<=n;i++)if(top[i]==i)gans(vc[i]);
	std::cout.precision(15);
	if(ans>1e100)puts("-1");else std::cout<<ans;
}