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
#define inf 92233720368547757
#define mn 100005
#define FLN "test"

vector <int> pos[105];
int n;
int s[105];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) 
	{
		cin>>s[i];
		pos[s[i]].push_back(i);
	}
	
	//count number of singles and big doubles
	int cnt=0, c2=0;
	for (int i=1; i<=100; i++) 
	{
		if (pos[i].size()==1) cnt++;
		else if (pos[i].size()>2) c2++;
	}
	
	if (cnt%2==1 && c2==0)
	{
		cout<<"NO";
		return 0;
	}
	
	vector <int> split={}, non={};
	
	for (int i=1; i<=100; i++) if (pos[i].size()==1) split.push_back(pos[i][0]);
	
	if (split.size()%2==1)
	{
		for (int i=1; i<=100; i++) if (pos[i].size()>2) 
		{
			split.push_back(pos[i][0]);
			for (int j=1; j<pos[i].size(); j++) non.push_back(pos[i][j]);
			pos[i].clear();
			break;
		}
	}
	for (int i=1; i<=100; i++) if (pos[i].size()>1) for (int j:pos[i]) non.push_back(j);
	
	char ans[105];
	int ptr=0;
	for (int i:split) 
	{
		ans[i]='A'+ptr%2;
		ptr++;
	}
	for (int i:non) ans[i]='A';
	cout<<"YES\n";
	for (int i=1; i<=n; i++) cout<<ans[i];
	
	
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_