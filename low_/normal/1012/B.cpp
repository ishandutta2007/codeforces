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
#define mn 200005
#define FLN "test"

int m, n, q;
pair <int, int> Pos[mn];
vector <pair <int, int> > Row[mn], Col[mn];
vector <int> dsk[mn];

//BFS
bool passed[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>q;
	
	for (int i=1; i<=q; i++) 
	{
		cin>>Pos[i].first>>Pos[i].second;
		Row[Pos[i].first].push_back(Pos[i]);
		
		Col[Pos[i].second].push_back(Pos[i]);
	}
	
	
	
	//Xu ly row -> tinh ra so canh phu het duoc
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<(int)Row[i].size()-1; j++)
		{
			dsk[Row[i][j].second].push_back(Row[i][j+1].second);
			dsk[Row[i][j+1].second].push_back(Row[i][j].second);
		}
	}
	
	//BFS
	for (int i=1; i<mn; i++) passed[i]=0;
	queue <int> Q;
	vector <int> luu;
	set <int> ss;
	int ans=0;
	int rans=-1;
	for (int i=1; i<=m; i++) if (!Col[i].empty()) if (!passed[i])
	{
		rans++;
//		cerr<<Col[i].size()<<"\n";
		luu.clear();
		luu.push_back(i);
		Q.push(i);
		ss.clear();
		passed[i]=1;
		int cnt=1;
		while (!Q.empty())
		{
			int temp=Q.front();
			Q.pop();
			
			for (int j=0; j<dsk[temp].size(); j++) if (!passed[dsk[temp][j]])
			{
				passed[dsk[temp][j]]=1;
				cnt++;
				luu.push_back(dsk[temp][j]);
				Q.push(dsk[temp][j]);
			}
		}
		for (int j:luu) for (int k=0; k<Col[j].size(); k++) ss.insert(Col[j][k].first);
		ans+=cnt*(int)(ss.size());
	}
	for (int i=1; i<=n; i++) if (Row[i].empty()) rans++;
	for (int i=1; i<=m; i++) if (Col[i].empty()) rans++;
	cout<<rans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: