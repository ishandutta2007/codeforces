#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,k,c,lb,ub,dwn;
vector<int> e[N];
set<int> ch[N];
int p[N],size[N],max_size[N];
int skey[N],deep[N],dddd[N];
bool del[N];
struct cmp
{
	inline bool operator()(int a,int b)
	{
		if(skey[a]!=skey[b])
			return skey[a]<skey[b];
		return a<b;
	}
};
set<int,cmp> S;
struct cmp2
{
	inline bool operator()(int a,int b)
	{
		if(deep[a]!=deep[b])
			return deep[a]<deep[b];
		return a<b;
	}
};
set<int,cmp2> Q[N];
vector<int> ans;
int get_center(int x,int father)
{
	int res=0,d;
	size[x]=1;
	for(int y:e[x])
		if(y!=father)
		{
			d=get_center(y,x);
			if(!res||max_size[res]>max_size[d])
				res=d;
			size[x]+=size[y];
			max_size[x]=max(max_size[x],size[y]);
		}
	max_size[x]=max(max_size[x],n-size[x]);
	if(!res||max_size[res]>max_size[x])
		res=x;
	return res;
}
void dfs(int x,int father,int rt)
{
	dddd[x]=rt;
	skey[rt]++;p[x]=father;deep[x]=deep[father]+1;
	size[x]=1;
	for(int y:e[x])
		if(y!=father)
		{
			dfs(y,x,rt);size[x]+=size[y];
			ch[x].insert(y);
		}
	lb+=size[x]&1;ub+=size[x];
	Q[rt].insert(x);
	return;
}
signed main()
{
	int x,y,z,w;
	register int i;
	scanf("%lld%lld",&n,&k);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	c=get_center(1,0);
	for(int x:e[c])
		dfs(x,c,x),S.insert(x),ch[c].insert(x);
	if(k<lb||k>ub||(k-lb)%2)
		return puts("NO"),0;
	else
		puts("YES");
	p[c]=c;
	while(1)
	{
		x=*S.rbegin();
		if(ub-dwn-deep[y=p[*Q[x].rbegin()]]*2<=k)
			break;
		dwn+=deep[y]*2;
		if((int)ch[y].size()>1)
			z=*ch[y].begin(),ch[y].erase(z),w=*ch[y].begin(),ch[y].erase(w);
		else
			z=*ch[y].begin(),ch[y].erase(z),w=y,ch[p[y]].erase(y);
		ans.push_back(z);ans.push_back(w);del[z]=del[w]=1;
		Q[x].erase(z);Q[x].erase(w);
		S.erase(x);skey[x]-=2;S.insert(x);
	}
	if(ub-dwn==k)
		goto end;
	for(i=1;i<=n;i++)
		if(i!=c&&dddd[i]==*S.rbegin()&&!del[i]&&ub-dwn-deep[i]*2==k&&!ch[i].empty())
		{
			z=*ch[i].begin();ch[i].erase(z);w=i;ch[p[i]].erase(i);
			ans.push_back(z);ans.push_back(w);del[z]=del[w]=1;
			x=dddd[i];
			S.erase(x);skey[x]-=2;S.insert(x);
			break;
		}
	end:;
	skey[c]=1;dddd[c]=c;S.insert(c);
//	for(int x:S)
//		printf("%lld!\n",x);
	for(i=1;i<=n;i++)
		ch[i].clear();
	for(i=1;i<=n;i++)
		if(!del[i])
			ch[dddd[i]].insert(i);
	while(!S.empty())
	{
		x=*S.begin();S.erase(x);
		if(skey[x]>0)
		{
			S.insert(x);break;
		}
	}
	while(!S.empty())
	{
		x=*S.rbegin();S.erase(x);
		y=*S.rbegin();S.erase(y);
		z=*ch[x].begin();ch[x].erase(z);
		w=*ch[y].begin();ch[y].erase(w);
		ans.push_back(z);ans.push_back(w);del[z]=del[w]=1;
		skey[x]--;skey[y]--;
		if(skey[x])
			S.insert(x);
		if(skey[y])
			S.insert(y);
	}
//	if(ans.size()!=n)
//		return 1;
	vector<int> cans=ans;
	sort(cans.begin(),cans.end());
//	for(i=2;i<=n;i++)
//		if(cans[i-1]==cans[i-2])
//			return -cans[i-1]*10000-c;
	while(!ans.empty())
	{
		z=ans.back();ans.pop_back();
		w=ans.back();ans.pop_back();
		printf("%lld %lld\n",z,w);
	}
	return 0;
}