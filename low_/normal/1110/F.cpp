#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 500005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n, q;
vector <pii> dsk[mn];
vector <pair <int, pii> > quer[mn];
int par[mn], W[mn], leafid[mn], leafcnt=0;
int Lleaf[mn], Rleaf[mn];
int ansQ[mn];
vector <int> Leaves;

class segment_tree{
private:
	int ST[8*mn], lazy[8*mn];
	
	void UPD(int id, int l, int r, int u, int v, int g)
	{
		if (lazy[id]!=0)
		{
			ST[id]+=lazy[id];
			if (r>l) lazy[2*id]+=lazy[id], lazy[2*id+1]+=lazy[id];
			lazy[id]=0;
		}
		
		if (r<u || l>v) return;
		if (u<=l && r<=v) 
		{
			ST[id]+=g;
			lazy[2*id]+=g;
			lazy[2*id+1]+=g;
			
			return;
		}
		
		int mid=(l+r)/2;
		UPD(2*id, l, mid, u, v, g);
		UPD(2*id+1, mid+1, r, u, v, g);
		ST[id]=min(ST[2*id], ST[2*id+1]);
	}
	
	int GET(int id, int l, int r, int u, int v)
	{
		if (lazy[id]!=0)
		{
			ST[id]+=lazy[id];
			if (r>l) lazy[id*2]+=lazy[id], lazy[2*id+1]+=lazy[id];
			lazy[id]=0;
		}
		
		if (r<u || l>v) return inf;
		if (u<=l && r<=v) return ST[id];
		int mid=(l+r)/2;
		return min(GET(2*id, l, mid, u, v), GET(2*id+1, mid+1, r, u, v));
	}
public:
	segment_tree()
	{
		for (int i=0; i<4*mn; i++) lazy[i]=ST[i]=0;
	}
	void update(int L, int R, int G)
	{
		UPD(1, 1, leafcnt, L, R, G);
	}
	int get(int L, int R)
	{
		return GET(1, 1, leafcnt, L, R);
	}
};

segment_tree ST1;

int DFS(int u)
{
	if (dsk[u].size()<2) 
	{
		leafcnt++;
		Lleaf[u]=Rleaf[u]=leafcnt;
		Leaves.push_back(u);
	//	ST1.update(leafcnt, leafcnt, dist);
	}
	else
	{
		for (pii j: dsk[u]) if (j.XX!=par[u])
		{
			par[j.XX]=u;
			DFS(j.XX);
			Lleaf[u]=min(Lleaf[u], Lleaf[j.XX]);
			Rleaf[u]=max(Rleaf[u], Rleaf[j.XX]);
		}
	}
}

void DFS1(int u, int dist)
{
//	cerr<<u<<" "<<dist<<'\n';
	if (dsk[u].size()==1) 
	{
		ST1.update(Lleaf[u], Rleaf[u], dist);
	}
	else for (pii j:dsk[u]) if (j.XX!=par[u])
	{
		DFS1(j.XX, dist+W[j.XX]);
	}
}

int CNP(int u)
{
	int l=0, r=Leaves.size()-1;
	while (r>l)
	{
		int mid=(l+r)/2;
		
		if (Leaves[mid]<=u) l=mid+1;
		else r=mid;
	}
	return l+1;
}

void DFS2(int u)
{
	ST1.update(Lleaf[u], Rleaf[u], -2*W[u]);
	ST1.update(1, leafcnt, W[u]);
	
	for (pair <int, pii> P: quer[u])
	{
		int l=CNP(P.YY.XX-1), r=CNP(P.YY.YY)-1;
//		cerr<<u<<" "<<l<<" "<<r<<"\n";
		ansQ[P.XX]=ST1.get(l, r);
	}
	
//	cout<<u<<":\n";
//	for (int i=1; i<=leafcnt; i++) cout<<ST1.get(i, i)<<" ";
//	cout<<'\n';
	
	for (pii i:dsk[u]) if (i.XX!=par[u]) DFS2(i.XX);
	
	ST1.update(Lleaf[u], Rleaf[u], 2*W[u]);
	ST1.update(1, leafcnt, -W[u]);
	
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<mn; i++) Lleaf[i]=inf, Rleaf[i]=-inf, W[i]=0;
	
	cin>>n>>q;
	int p, w, l, r, v;
	for (int i=2; i<=n; i++)
	{
		cin>>p>>w;
		W[i]=w;
		dsk[p].push_back({i, w});
		dsk[i].push_back({p, w});
	}	
	
	
	for (int i=1; i<=q; i++)
	{
		cin>>v>>l>>r;
		
		quer[v].push_back({i, {l, r}});
	}
	
	for (int i=1; i<=n; i++) sort(dsk[i].begin(), dsk[i].end());
	
	DFS(1);
//	sort(Leaves.begin(), Leaves.end());
	Leaves.push_back(inf);
	DFS1(1, 0);
	DFS2(1);
	for (int i=1; i<=q; i++) cout<<ansQ[i]<<"\n";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/