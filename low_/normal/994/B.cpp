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

pair <int, pair <int, int> > P[mn];
int n, k;
int ans[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for (int i=1; i<=n; i++) cin>>P[i].first;
	for (int i=1; i<=n; i++) cin>>P[i].second.first, P[i].second.second=i;
	for (int i=1; i<=n; i++) ans[i]=P[i].second.first;
	
	sort(P+1, P+n+1);
	priority_queue <int> pq;
	int ptr=0;
	
	for (int i=1; i<=n; i++)
	{
		ans[P[i].second.second]+=ptr;
		
		pq.push(-P[i].second.first);
		ptr+=P[i].second.first;
		if (pq.size()>k) 
		{
			ptr+=pq.top();
			pq.pop();
		}
	}
	
	for (int i=1; i<=n; i++) cout<<ans[i]<<' '; 
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: