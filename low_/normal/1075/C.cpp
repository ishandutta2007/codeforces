#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
#include<sstream>
#include<bitset>
#include<ctime>
using namespace std;
#define int long long
#define inf 444444444444444444
#define mn 100005
#define FLN "test"

vector <int> vert={1000*1000*1000};
map <int, vector <pair <int, int> > > hor;
vector <int> MEX;

int m, n;

int CNP(int u, int l, int r)
{
	if (u<MEX[l]) return l-1;
	if (u>=MEX[r]) return r;
	
	int mid=(l+r)/2;
	if (u<MEX[mid]) return CNP(u, l, mid);
	else return CNP(u, mid+1, r);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen(FLN".inp", "r", stdin);
//	freopen(FLN".out", "w", stdout);
	
	int x1, x2, y;
	cin>>n>>m;
	for (int i=1; i<=n; i++)
	{
		cin>>x1;
		vert.push_back(x1);
	}
	for (int i=1; i<=m; i++)
	{
		cin>>x1>>x2>>y;
		if (hor.count(y)==0) hor[y]={{x1, x2}};
		else hor[y].push_back({x1, x2});
	}
	
	for (pair <int, vector <pair <int, int> > > pii:hor)
	{
		vector <pair <int, int> > wall=pii.second;
		sort(wall.begin(), wall.end());
		int q=1;
		for (int i=0; i<wall.size(); i++)
		{
			if (q<wall[i].first) break;
			q=wall[i].second+1;
		}
		MEX.push_back(q);
	}
	
	sort(MEX.begin(), MEX.end());
	sort(vert.begin(), vert.end());
	
//	for (int i:MEX) cerr<<i<<' ';
	
	int ans=inf;
	if (MEX.empty()) ans=0;
	else
	{
		for (int i=0; i<vert.size(); i++)
		{
			ans=min(i+(int)((MEX.size()-1)-CNP(vert[i], 0, MEX.size()-1)), ans);
		//	cerr<<i<<' '<<(MEX.size()-1)-CNP(vert[i], 0, MEX.size()-1)<<'\n';
		}
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_