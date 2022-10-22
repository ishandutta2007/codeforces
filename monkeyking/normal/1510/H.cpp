#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
template <typename T1,typename T2> inline void chmax(T1 &x,const T2 &b) {(x=x>b?x:b);}
const int inf=1039714778;
const ll llinf=1LL*inf*inf;
using namespace std;
int n;
int l[2005];
int r[2005];
vector<int> edges[2005];
vector<int> roots;
int resl[2005];
int resr[2005];
int szlim[2005];

inline void compressAddress(ll &t,int a,int b,int c,int d,int e,int ch=0)
{
	t=0;
	(((((((((t|=a)<<=11)|=b)<<=11)|=c)<<=11)|=d)<<=11)|=e);
	if(ch) t|=(1LL<<60);
}

inline int decompressAddress(ll t,int &a,int &b,int &c,int &d,int &e)
{
	int ch=(bool)(t&(1LL<<60));
	int mask=(1<<11)-1;
	e=t&mask;t>>=11;
	d=t&mask;t>>=11;
	c=t&mask;t>>=11;
	b=t&mask;t>>=11;
	a=t&mask;
	return ch;
}

struct Value
{
	int a[2][2];
	pair<ll,ll> trace[2][2];
	int* operator [] (int x){
		return a[x];
	}
	const int* operator [] (int x)const{
		return a[x];
	}
}vmin;
vector<vector<Value> > dp[2005];
int sz[2005];
int depth[2005];
int fn[2005];//
/**
 * 
 * 
 * ++
 */


int getInfo(int x,int d=0)
{
	depth[x]=d;
	sz[x]=1;
	for(auto u:edges[x])
	{
		sz[x]+=getInfo(u,d+1);
	}
	fn[x]=(sz[x]==1?0:edges[x].size()+1);
	szlim[x]=min(sz[x]-1,depth[x])+2;
	return sz[x];
}

void merge(vector<Value> &a,vector<Value> &b,vector<Value>&c,int pm,int x,int u,int id)
{
	int n=a.size()-1,m=b.size()-1,t=n+m+1;
	c.resize(min(szlim[x],t+1),vmin);
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<=m;j++)
		{
			for(int l1=0;l1<2;l1++)
			{
				for(int l2=0;l2<2;l2++)
				{
					for(int r1=0;r1<2;r1++)
					{
						for(int r2=0;r2<2;r2++)
						{
							int forceCh=false;
							if(l2 || r1) forceCh=true;
							for(int ch=forceCh;ch<2;ch++)
							{
								if(ch) assert(pm!=0);
								if(i+j+ch>=szlim[x]) continue;
								// chmax(c[i+j+ch][l1][r2],a[i][l1][l2]+b[j][r1][r2]+(ch?pm:0));
								if(c[i+j+ch][l1][r2]<a[i][l1][l2]+b[j][r1][r2]+(ch?pm:0))
								{
									// if(x==0 && id==1 && i+j+ch==1 && l1==0 && r2==0)
									// {
									// 	debug(ch);
									// }
									c[i+j+ch][l1][r2]=a[i][l1][l2]+b[j][r1][r2]+(ch?pm:0);
									compressAddress(c[i+j+ch].trace[l1][r2].first,x,id,i,l1,l2,ch);
									// int ta,tb,tc,td,te;
									// ch=decompressAddress(c[i+j+ch].trace[l1][r2].first,ta,tb,tc,td,te);
									compressAddress(c[i+j+ch].trace[l1][r2].second,u,fn[u],j,r1,r2);
								}
							}
						}
					}
				}
			}
		}
	}
}

void dfs(int x)
{
	for(auto u:edges[x])
	{
		dfs(u);
	}
	int n=edges[x].size();
	int m=1;
	dp[x].resize(fn[x]+1);
	dp[x][0].resize(m+1,vmin);
	if(n==0)//
	{
		dp[x][0][0][0][0]=r[x]-l[x];
		return;
	}
	else//0
	{
		int u=edges[x][0],lef=l[u]-l[x];
		m+=sz[u];
		dp[x][1]=dp[u][fn[u]];
		dp[x][1].resize(m+1,vmin);
		for(int i=0;i<dp[u][fn[u]].size();i++)
		{
			for(int l=0;l<2;l++)
			{
				for(int r=0;r<2;r++)
				{
					compressAddress(dp[x][1][i].trace[l][r].first,u,fn[u],i,l,r);
					dp[x][1][i].trace[l][r].second=-llinf-1;
				}
			}
		}
		//x
		for(int i=m;i>=0;i--)
		{
			for(int r=0;r<2;r++)
			{
				// chmax(dp[x][1][i][1][r],dp[x][1][i][0][r]);
				if(dp[x][1][i][1][r]<dp[x][1][i][0][r])
				{
					dp[x][1][i][1][r]=dp[x][1][i][0][r];
					compressAddress(dp[x][1][i].trace[1][r].first,x,1,i,0,r);
					dp[x][1][i].trace[1][r].second=-1-l[u];
				}
			}
		}
		// 
		for(int i=0;i<=m;i++)
		{
			for(int r=0;r<2;r++)
			{
				dp[x][1][i][1][r]+=lef;
			}
		}
	}

	for(int i=1;i<n;i++)
	{
		int u=edges[x][i],md=l[edges[x][i]]-r[edges[x][i-1]];
		merge(dp[x][i],dp[u][fn[u]],dp[x][i+1],md,x,u,i);
	}

	//
	vector<Value> &v=dp[x][n];int rgt=r[x]-r[edges[x][n-1]];
	dp[x][n].resize(sz[x]+1,vmin);
	for(int i=sz[x];i>=0;i--)
	{
		for(int l=0;l<2;l++)
		{
			// chmax(v[i][l][1],v[i][l][0]);
			if(v[i][l][1]<v[i][l][0])
			{
				v[i][l][1]=v[i][l][0];
				compressAddress(v[i].trace[l][1].first,x,n,i,l,0);
				v[i].trace[l][1].second=-1-r[edges[x][n-1]];
			}
		}
	}
	for(int i=0;i<=sz[x];i++)
	{
		for(int l=0;l<2;l++)
		{
			v[i][l][1]+=rgt;
		}
	}
	///
	//-1
	//
	dp[x][fn[x]].resize(min(szlim[x],sz[x]),vmin);
	for(int i=0;i<=sz[x];i++)
	{
		for(int l=0;l<2;l++)
		{
			for(int r=0;r<2;r++)
			{
				for(int fl=l;fl<2;fl++)
				{
					for(int fr=r;fr<2;fr++)
					{
						if(i+(fl-l)+(fr-r)-1>=min(szlim[x],sz[x])) continue;
						if(i+(fl-l)+(fr-r)-1<0) continue;
						if(dp[x][fn[x]][i+(fl-l)+(fr-r)-1][l][r]<v[i][fl][fr])
						{
							dp[x][fn[x]][i+(fl-l)+(fr-r)-1][l][r]=v[i][fl][fr];
							compressAddress(dp[x][fn[x]][i+(fl-l)+(fr-r)-1].trace[l][r].first,x,n,i,fl,fr);
							dp[x][fn[x]][i+(fl-l)+(fr-r)-1].trace[l][r].second=-llinf;
						}
					}
				}
			}
		}
	}
}

vector<int> chSegs;

void pushSeg(int a,int b,int c,int d,int e)
{
	// debug(a,b,c,d,e,dp[a][b][c][d][e]);
	if(edges[a].size()==0)//
	{
		assert((b|c|d|e)==0);
		chSegs.push_back(l[a]);
		chSegs.push_back(r[a]);
		return;
	}
	int na,nb,nc,nd,ne;
	pair<ll,ll> &o=dp[a][b][c].trace[d][e];
	int ch=decompressAddress(o.first,na,nb,nc,nd,ne);
	// debug(ch);
	// debug(a,b,c,d,e,na,nb,nc,nd,ne);
	if(o.second>=0)
	{
		// if(a==2 && ch)
		// {
		// 	debug(b,ne,r[edges[a][b-2]]);
		// }
		if(ch && ne==0)
		{
			chSegs.push_back(r[edges[a][b-2]]);
		}
		pushSeg(na,nb,nc,nd,ne);
		decompressAddress(o.second,na,nb,nc,nd,ne);
		if(ch && nd==0)
		{
			chSegs.push_back(l[edges[a][b-1]]);
		}
		pushSeg(na,nb,nc,nd,ne);
	}
	else if(o.second==-llinf-1)
	{
		pushSeg(na,nb,nc,nd,ne);
	}
	else
	{
		// debug("FUCK");
		// assert(na==a);
		// assert(nb==b);
		// assert(mabs(nc-c)<=1);
		int pl,pr;
		// if(o.second==-llinf)
		// {
		// 	debug(a,nd!=d,ne!=e);
		// }
		if(o.second==-llinf) pl=l[a],pr=r[a];
		else pl=pr=-o.second-1;
		if(nd!=d)
		{
			chSegs.push_back(pl);
		}
		if(ne!=e)
		{
			chSegs.push_back(pr);
		}
		pushSeg(na,nb,nc,nd,ne);
	}
}

int solve(int x)
{
	getInfo(x);
	dfs(x);
	int val=dp[x][fn[x]][0][0][0];
	pushSeg(x,fn[x],0,0,0);
	return val;
}

int main()
{
	// freopen("input.txt","r",stdin);
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) vmin[i][j]=-inf;

	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>l[i]>>r[i];
	}
	for(int i=0;i<n;i++)
	{
		pii fa=mp(-inf,-1);
		for(int j=0;j<n;j++)
		{
			if(l[j]<l[i] && r[j]>r[i]) chmax(fa,mp(l[j],j));
		}
		if(fa.second!=-1) edges[fa.second].push_back(i);else roots.push_back(i);
	}
	// debug(roots);

	for(int i=0;i<n;i++)
	{
		sort(all(edges[i]),[](const int &a,const int &b){return l[a]<l[b];});
	}

	vector<pii> allres;
	int res=0;
	for(auto x:roots)
	{
		res+=solve(x);
	}
	cout<<res<<endl;
	sort(all(chSegs));
	assert(chSegs.size()==n*2);
	memset(resl,-1,sizeof(resl));
	for(int i=0;i<n*2;i+=2)
	{
		int lp=chSegs[i];
		int rp=chSegs[i+1];
		pii o=mp(-inf,-1);
		for(int j=0;j<n;j++)
		{
			if(resl[j]==-1 && l[j]<=lp && r[j]>=rp) chmax(o,mp(l[j],j));
		}
		assert(o.second!=-1);
		resl[o.second]=lp;
		resr[o.second]=rp;
	}
	for(int i=0;i<n;i++)
	{
		assert(resl[i]>=l[i] && resr[i]<=r[i]);
		res-=resr[i]-resl[i];
		printf("%d %d\n",resl[i],resr[i]);
	}
	assert(res==0);
	// return res;
	// debug(res);
	// debug(chSegs);
	// for(int i=0;i<n*2;i+=2)
	// {
	// 	printf("%d %d\n",chSegs[i],chSegs[i+1]);
	// }
	return 0;
}