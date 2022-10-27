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
#define FLN "test"

pair <int, int> P[2][5];
set <pair <int, int> > ss[2];

int CCW(pair <int, int> A, pair <int, int> B, pair <int, int> C)
{
	int ret=(C.first-B.first)*(B.second-A.second)-(B.first-A.first)*(C.second-B.second);
	if (ret>0) return 1;
	else if (ret==0) return 0;
	else if (ret<0) return -1;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i=0; i<2; i++) 
	{
		for (int j=0; j<4; j++) cin>>P[i][j].first>>P[i][j].second;
		P[i][4]=P[i][0];
	}
	
	for (int i=0; i<2; i++)
	{
		int icrx, icry, ptrx, ptry;
		
		for (int j=0; j<4; j++)
		{
			if (P[i][j].first<P[i][j+1].first) icrx=1;
			else if (P[i][j].first==P[i][j+1].first) icrx=0;
			else icrx=-1;
			
			if (P[i][j].second<P[i][j+1].second) icry=1;
			else if (P[i][j].second==P[i][j+1].second) icry=0;
			else icry=-1;
			
//			cerr<<icrx<<" "<<icry<<"\n";
			ptrx=P[i][j].first, ptry=P[i][j].second;
			while (ptrx!=P[i][j+1].first || ptry!=P[i][j+1].second)
			{
				ss[i].insert({ptrx, ptry});
				ptrx+=icrx;
				ptry+=icry;
			}
		}
	}
	
	int ans=ss[0].size()+ss[1].size();
	for (pair <int, int> Pi:ss[1]) ss[0].insert(Pi);
	if (ss[0].size()<ans) 
	{
		cout<<"YES";
		return 0;
	}
	
//	cerr<<"ll1\n";
	int l=0;
	for (int i=0; i<4; i++) 
	{
		l=0;
		for (int j=0; j<4; j++) l+=CCW(P[0][i], P[1][j], P[1][j+1]);
		cerr<<l<<"\n";
		if (abs(l)==4) 
		{
			cout<<"YES"; return 0;
		}
		
		l=0;
		for (int j=0; j<4; j++) l+=CCW(P[1][i], P[0][j], P[0][j+1]);
		cerr<<l<<"\n";
		if (abs(l)==4) 
		{
			cout<<"YES"; return 0;
		}
	}
	cout<<"NO";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: