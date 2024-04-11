#include<bits/stdc++.h>
using namespace std;
int n,x,y,z,sub[111111],rt,cnt,a[111111],pos[111111],wh,Rt[111111],sz,tree[11111111],ls[11111111],rs[11111111];
vector<pair<int,int> > g[111111];
int l,r,mid,pp;
long long ans;
set<int> s[111111];
set<pair<int,int> > ss;
set<pair<int,int> >::iterator it;
void dfs(int i,int fa)
{
	sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		dfs(to,i);
		sub[i]+=sub[to];
		ans+=(2ll*val*min(sub[to],n-sub[to]));
	}
}
pair<int,int> findgrav(int i,int fa)
{
	pair<int,int> res=make_pair(1e9,1e9);
	int mx=0;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa) continue;
		res=min(res,findgrav(to,i));
		mx=max(mx,sub[to]);
	}
	mx=max(mx,n-sub[i]);
	res=min(res,make_pair(mx,i));
	return res;
}
void dft(int i,int fa)
{
	s[cnt].insert(i);
	a[cnt]+=2;pos[i]=cnt;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa) continue;
		dft(to,i);
	}
}
void updt(int x)
{
	ss.erase(ss.find(make_pair(a[x],x)));
	a[x]--;
	ss.insert(make_pair(a[x],x));
}
void upd(int x,int l,int r,int &nw,int y)
{
	if (!nw)
	{
		nw=++sz;
	}
	tree[nw]+=y;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x>mid) upd(x,mid+1,r,rs[nw],y);
	else upd(x,l,mid,ls[nw],y);
}
int query(int beg,int en,int l,int r,int node)
{
	if (l>en || r<beg) return 0;
	if (!node) return 0;
	if (l>=beg && r<=en) return tree[node];
	int mid=(l+r)>>1;
	return query(beg,en,l,mid,ls[node])+query(beg,en,mid+1,r,rs[node]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	dfs(1,0);
	rt=findgrav(1,0).second;
	for (int i=0;i<g[rt].size();i++)
	{
		int to=g[rt][i].first;
		++cnt;
		dft(to,rt);
	}
	++cnt;
	s[cnt].insert(rt);
	a[cnt]=0;
	pos[rt]=cnt;
	printf("%lld\n",ans);
	for (int i=1;i<=cnt;i++) ss.insert(make_pair(a[i],i));
	for (int i=1;i<=n;i++)
	{
		upd(i,1,n,Rt[0],1);
		upd(i,1,n,Rt[pos[i]],1);
	}
	for (int i=1;i<=n;i++)
	{
		wh=pos[i];
		updt(wh);
		it=ss.end();it--;
		if ((it->first)==n-i+1)
		{
			int ff=it->second;
			updt(ff);
			printf("%d ",*s[ff].begin());
			upd(*s[ff].begin(),1,n,Rt[0],-1);
			upd(*s[ff].begin(),1,n,Rt[ff],-1);
			s[ff].erase(s[ff].begin());
		}
		else
		{
			l=1;r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (query(1,mid,1,n,Rt[0])>query(1,mid,1,n,Rt[wh])) r=mid-1;
				else l=mid+1;
			}
			if (i==rt)
			{
				l=min(l,i);
			}
			printf("%d ",l);
			updt(pos[l]);
			s[pos[l]].erase(l);
			upd(l,1,n,Rt[0],-1);
			upd(l,1,n,Rt[pos[l]],-1);
		}
	}
	return 0;
}