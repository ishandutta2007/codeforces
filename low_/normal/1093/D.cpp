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
#define mn 300005
#define inf 4444444444444444444
#define mod 998244353
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int PoW2[mn];

int n, m, u, v;
vector <int> dsk[mn];
int H[mn];

deque <int> Q;

int BFS(int u)
{
	Q={u};
	H[u]=1;
	int od=0, al=0;
	while (!Q.empty())
	{
		int t=Q.front();
		Q.pop_front();
		od+=H[t]%2, al++;
		
		for (int j:dsk[t]) 
		{
			if (H[j]==-1) Q.push_back(j), H[j]=H[t]+1;
			else if (H[j]%2==H[t]%2) return 0;
		}
	}
	return (PoW2[od]+PoW2[al-od])%mod;
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
	
	PoW2[0]=1;
	for(int i=1; i<mn; i++) PoW2[i]=(PoW2[i-1]*2)%mod;
	
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n>>m;
		for (int i=1; i<=n; i++) dsk[i].clear(), H[i]=-1;
		for (int i=1; i<=m; i++)
		{
			cin>>u>>v;
			dsk[u].push_back(v);
			dsk[v].push_back(u);
		}
		
		int ans=1;
		for (int i=1; i<=n; i++) if (H[i]==-1) ans=(ans*BFS(i))%mod;
		cout<<ans<<"\n";
	}
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/