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

int n, k;
vector <int> dsk[mn];
int H[mn], passed[mn], Child_cnt[mn];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	int u, v;
	for (int i=1; i<=n; i++)
	{
		if (i<n)
		{
			cin>>u>>v;
			dsk[u].push_back(v);
			dsk[v].push_back(u);
		}
		H[i]=-1;
		passed[i]=Child_cnt[i]=0;
	}
	
	queue <int> Q;
	for (int i=1; i<=n; i++) if (dsk[i].size()==1)
	{
		H[i]=0;
//		passed[i]=1;
		Q.push(i);
	}
	
	while (!Q.empty())
	{
		int t=Q.front();
		Q.pop();
		if (passed[t]==1) continue;
		
		passed[t]=1;
		if (H[t]>0 && Child_cnt[t]<3)
		{
			cerr<<"NO-CHILD ERROR!";
			cout<<"No\n";
			return 0;
		}
		
		for (int i:dsk[t]) if (passed[i]==0)
		{
			if (H[i]==-1)
			{
				H[i]=H[t]+1;
				Q.push(i);
			}
			else if (H[i]!=H[t]+1)
			{
				cerr<<"UNBALANCED!";
				cout<<"No\n";
				return 0;
			}
			Child_cnt[i]++;
		}
	}
	
	int kcnt=0;
	for (int i=1; i<=n; i++) kcnt+=(H[i]==k);
	
//	for (int i=1; i<=n; i++) cerr<<i<<' '<<H[i]<<'\n';
	
	if (kcnt==1) cout<<"Yes\n";
	else 
	{
		cerr<<"MORE THAN K HED";
		cout<<"No\n";
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_