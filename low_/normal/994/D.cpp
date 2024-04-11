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

int n, m;
set <pair <int, int> > ss[2];
pair <int, int> t;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for (int i=0; i<n; i++)
	{
		cin>>t.first>>t.second;
		if (t.first>t.second) 
		{
			t.first+=t.second;
			t.second=t.first-t.second;
			t.first-=t.second;
		}
		ss[0].insert(t);
	}
	for (int i=0; i<m; i++)
	{
		cin>>t.first>>t.second;
		if (t.first>t.second) 
		{
			t.first+=t.second;
			t.second=t.first-t.second;
			t.first-=t.second;
		}
		ss[1].insert(t);
	}
	
	bool pos[10]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (pair <int, int> p1:ss[0]) 
	{
		for (pair <int, int> p2:ss[1])
		{
			if (p1==p2) continue;
			
			if (p1.first==p2.first || p1.first==p2.second) pos[p1.first]=1;
			else if (p1.second==p2.first || p1.second== p2.second) pos[p1.second]=1; 
		}
	}
	
	int ans=0;
	for (int i=1; i<10; i++) ans+=(int)pos[i];
	if (ans==1) 
	{
		for (int i=1; i<10; i++) if (pos[i]) cout<<i;
	}
	else
	{
		ans=0;
		for (pair <int, int> p1:ss[0]) 
		{
			for (int i=1; i<10; i++) pos[i]=0;
			for (pair <int, int> p2:ss[1])
			{
				if (p1==p2) continue;
				
				if (p1.first==p2.first || p1.first==p2.second) pos[p1.first]=1;
				else if (p1.second==p2.first || p1.second== p2.second) pos[p1.second]=1;
			}
			
			if (pos[p1.first] && pos[p1.second]) ans=-1;
		}
		
		for (pair <int, int> p1:ss[1]) 
		{
			for (int i=1; i<10; i++) pos[i]=0;
			for (pair <int, int> p2:ss[0])
			{
				if (p1==p2) continue;
				
				if (p1.first==p2.first || p1.first==p2.second) pos[p1.first]=1;
				else if (p1.second==p2.first || p1.second== p2.second) pos[p1.second]=1;
			}
			
			if (pos[p1.first] && pos[p1.second]) ans=-1;
		}
		
		cout<<ans;
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: