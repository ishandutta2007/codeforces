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

string P;
int n;

deque <pair <int, int> > seat; //width = first, index = second

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	seat.assign(n, {0, 0});
	for (int i=0; i<n; i++) 
	{
		cin>>seat[i].first;
		seat[i].second=i;
	}
	cin>>P;
	
	sort(seat.begin(), seat.end());
	
	priority_queue <pair <int, int> > PQ;
	
	pair <int, int> temp;
	for (int i=0; i<n*2; i++)
	{
		if (P[i]=='0')
		{
			temp=seat.front();
			seat.pop_front();
			cout<<temp.second+1<<" ";
			PQ.push(temp);
		}
		else
		{
			temp=PQ.top();
			PQ.pop();
			cout<<temp.second+1<<" ";
		}
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: