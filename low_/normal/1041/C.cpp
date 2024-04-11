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

int n, m, d;
pair <int, int> A[mn*2];
int ans[mn*2];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>d;
	for (int i=1; i<=n; i++) cin>>A[i].first, A[i].second=i;
	sort(A+1, A+n+1);
	
	queue <pair <pair <int, int>, int> > Q;
	int t1, t2;
	int A1=0;
	for (int i=1; i<=n; i++)
	{
		if (Q.empty() || A[i].first+Q.front().first.first<=d)
		{
			t1=Q.size()+1;
			A1=max(A1, t1);
			ans[A[i].second]=t1;
			Q.push({{-A[i].first, A[i].second}, t1});
		}
		else 
		{
			t1=Q.front().second;
			ans[A[i].second]=t1;
			Q.pop();
			Q.push({{-A[i].first, A[i].second}, t1});
		}
	}
	
	cout<<A1<<'\n';
	for (int i=1; i<=n; i++) cout<<ans[i]<<' ';
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_