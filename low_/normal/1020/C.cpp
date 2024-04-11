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
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

int m, n;
pair <int, int> voters[mn];
vector <int> party[mn];
int ans[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=0; i<mn; i++) ans[i]=inf;
	for (int i=1; i<=n; i++) 
	{
		cin>>voters[i].second>>voters[i].first;
		party[voters[i].second].push_back(voters[i].first);
	}
	for (int i=1; i<=m; i++) sort(party[i].begin(), party[i].end());
	
//	cerr<<party[1].size()<<' '<<party[3].size();
	if (m==1)
	{
		cout<<0;
		return 0;
	}
	for (int i=2; i<=m; i++)
	{
		if (party[i].size()>=party[1].size()) break;
		if (i==m) 
		{
			cout<<0;
			return 0;
		}
	}
//	cerr<<'-';
	vector <int> buffer;
	for (int i=n-party[1].size(); i>0; i--) //for so vote mua chuoc
	{
		int cnt=i;
		ans[i]=0;
		buffer.clear();
		int k;
		for (int j=2; j<=m; j++) 
		{
			k=0;
			while (party[j].size()-k>i+party[1].size()-1)
			{
				ans[i]+=party[j][k];
				k++;
				cnt--;
			}
			while (k<party[j].size())
			{
				buffer.push_back(party[j][k]);
				k++;
			}
		}
		
		sort(buffer.begin(), buffer.end());
		for (int j=0; j<cnt; j++) ans[i]+=buffer[j];
//		cerr<<ans[i]<<'\n';
	}
	

	
	int ANS=inf;
	for (int i=0; i<=n; i++) ANS=min(ans[i], ANS);
	cout<<ANS;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: