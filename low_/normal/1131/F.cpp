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
#define mn 200005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int n;
int root[mn], L[mn], R[mn];

int getroot(int u)
{
	if (root[u]==u) return u;
	return root[u]=getroot(root[u]);
}

vector <int> dsk[mn];
int passed[mn];

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<mn; i++) root[i]=L[i]=R[i]=i;
	
	cin>>n;
	int u, v;
	for (int i=1; i<n; i++)
	{
		cin>>u>>v;
		int l=getroot(u), r=getroot(v);
		root[getroot(u)]=getroot(v);
//		cerr<<R[l]<<" "<<L[r]<<"\n";
		dsk[R[l]].push_back(L[r]);
		dsk[L[r]].push_back(R[l]);
		L[r]=L[l];
	}
	
	u=0;
	int cnt=0;
	for (int i=1; i<=n; i++) if (dsk[i].size()==1)
	{
		if (u!=0) v=i;
		else u=i;
		cnt++;
	}
	
//	cerr<<cnt<<" "<<u<<" "<<v<<"\n";
	vector <int> ans={u};
	passed[u]=1;
	for (int i=1; i<n; i++)
	{
	//	cerr<<u<<"\n";
		int t=dsk[u][0];
		if (passed[t]==1) t=dsk[u][1];
		u=t;
		passed[u]=1;
		ans.push_back(u);
	}
	
	for (int i:ans) cout<<i<<" ";
	
	
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/