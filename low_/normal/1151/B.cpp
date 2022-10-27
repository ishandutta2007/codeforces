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
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

vector <pii> A[505];

int n, m;

bool checkNie()
{
	for(int i=0; i<n; i++) if (A[i].size()>1) return 0;
	return 1;
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
	
	cin>>n>>m;
	for (int i=0; i<n; i++) A[i].assign(m, {0, 0});
	for (int i=0; i<n; i++) for (int j=0; j<m; j++)
	{
		cin>>A[i][j].XX, A[i][j].YY=j+1;
	}
	
	for (int i=0; i<n; i++)
	{
		sort(A[i].begin(), A[i].end());
		vector <pii> temp={A[i][0]};
		for (int j=1; j<m; j++) if (A[i][j].XX>A[i][j-1].XX) temp.push_back(A[i][j]);
		A[i]=temp;
	}
	
	if (checkNie())
	{
		int temp=0;
		for (int i=0; i<n; i++) temp^=A[i][0].XX;
		if (temp==0) cout<<"NIE";
		else 
		{
			cout<<"TAK\n";
			for (int i=0; i<n; i++) cout<<A[i][0].YY<<" ";
		}
		return 0;
	}
	
	cout<<"TAK\n";
	int check1=0;
	for (int i=0; i<n; i++) check1^=A[i].back().XX;
	if (check1==0)
	{
		for (int i=0; i<n; i++) if (A[i].size()>1)
		{
			A[i].pop_back();
			break;
		}
		
		for (int i=0; i<n; i++) check1^=A[i].back().XX;
	}
	for (int i=0; i<n; i++) cout<<A[i].back().YY<<" ";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/