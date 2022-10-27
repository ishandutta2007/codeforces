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

deque <int> ans;
deque <pair <int, int> > Neg, Zer, Pos;

int n, A[mn*2];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>A[i];
	
	for (int i=1; i<=n; i++)
	{
		if (A[i]>0) Pos.push_back({A[i], i});
		else if (A[i]<0) Neg.push_back({A[i], i});
		else Zer.push_back({A[i], i});
	}
	
	//GREEDY PROCESSING Neg
	sort(Neg.begin(), Neg.end());
	for (int i=0; i<Neg.size(); i++) Neg[i].first=-1;
	while (Neg.size()>2)
	{
		ans.push_back(1);
		ans.push_back(Neg[0].second);
		ans.push_back(Neg[1].second);
		Neg[1].first*=Neg[0].first;
		Neg.pop_front();
	}
	
	if (Neg.size()==2)
	{
		if (Neg[0].first<0) 
		{
			ans.push_back(1);
			ans.push_back(Neg[0].second);
			ans.push_back(Neg[1].second);
			Neg[1].first*=Neg[0].first;
			Neg.pop_front();
		}
		
		Pos.push_back(Neg[0]);
		if (Neg.size()>1) Zer.push_back(Neg[1]); //Throw to trash
	}
	else if (Neg.size()==1) Zer.push_back(Neg[0]);
	
	//Processing trashes
	while (Zer.size()>1)
	{
		ans.push_back(1);
		ans.push_back(Zer[0].second);
		ans.push_back(Zer[1].second);
		Zer.pop_front();
	}
	
	//Removing trashes
	if (Zer.size()>0 && Pos.size()>0)
	{
		ans.push_back(2);
		ans.push_back(Zer[0].second);
	}
	
	//Positivity
	while (Pos.size()>1)
	{
		ans.push_back(1);
		ans.push_back(Pos[0].second);
		ans.push_back(Pos[1].second);
		Pos.pop_front();
	}
	
	int t;
	while (!ans.empty())
	{
		t=ans.front();
		ans.pop_front();
		cout<<t<<' '<<ans.front()<<' ';
		ans.pop_front();
		if (t==1) 
		{
			cout<<ans.front()<<' ';
			ans.pop_front();
		}
		cout<<'\n';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_