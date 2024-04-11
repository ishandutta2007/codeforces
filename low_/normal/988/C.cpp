#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define mod 1000000007

vector <pair <int, int> > seq[mn*2];
int sum[mn*2];

int CNP(int ind, int u, int l, int r)
{
	if (u>seq[ind][r].first || u<seq[ind][l].first) return -1;
	if (l==r) return seq[ind][l].second;
	
	int mid=(l+r)/2;
	if (u>seq[ind][mid].first) return CNP(ind, u, mid+1, r);
	else return CNP(ind, u, l, mid);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int k, n, t;
	cin>>k;
	for (int i=1; i<=k; i++)
	{
		sum[i]=0;
		cin>>n;
		for (int j=1; j<=n; j++)
		{
			cin>>t;
			seq[i].push_back({t, j});
			sum[i]+=t;
		}
	}
	
	map <int, pair <int, int> > MAP;
	MAP.clear();
	for (int i=1; i<=k; i++)
	{
		for (int j=0; j<seq[i].size(); j++) if (MAP.count(sum[i]-seq[i][j].first)==1)
		{
			cout<<"YES\n";
			cout<<MAP[sum[i]-seq[i][j].first].first<<' '<<MAP[sum[i]-seq[i][j].first].second<<"\n"<<i<<" "<<j+1;
			return 0;
		}
		
		for (int j=0; j<seq[i].size(); j++) MAP[sum[i]-seq[i][j].first]={i, j+1};
	}
	
	cout<<"NO\n";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: