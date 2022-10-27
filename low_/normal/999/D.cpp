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
#define mn 300005
#define FLN "test"

int n, m, d;
int A[mn];
vector <int> V[mn];
deque <int> Mo, Le;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	d=n/m;
	Mo.clear();
	Le.clear();
	for (int i=1; i<=n; i++)
	{
		cin>>A[i];
		V[A[i]%m].push_back(i);
	}
	
	int ans=0, t1, t2, t3;
	
	for (int i=0; i<m; i++)
	{
//		cerr<<i<<" "<<V[i].size()<<"\n";
		if (V[i].size()<d) 
		{
			t2=Mo.size();
			t3=d-V[i].size();
			while (min(t2, t3)>0)
			{
				t2--;
				t3--;
				t1=i-(A[Mo.front()]%m);
				ans+=t1;
				A[Mo.front()]+=t1;
				Mo.pop_front();
			}
			
			for (int j=0; j<t3; j++) Le.push_back(i);
		}
		else while (V[i].size()>d)
		{
			Mo.push_back(V[i].back());
			V[i].pop_back();
		}
	}
	
//	cerr<<Mo.size()<<" "<<Le.size()<<"\n";
//	
//	for (int q:Mo) cerr<<q<<" ";
//	cerr<<"\n";
//	for (int q:Le) cerr<<q<<" ";
//	cerr<<"\n";
	
	for (int i=0; i<Mo.size(); i++)
	{
		t1=Le[i]-(A[Mo[i]]%m)+m;
		ans+=t1;
		A[Mo[i]]+=t1;
//		Mo.pop_back();
	}
	cout<<ans<<"\n";
	for (int i=1; i<=n; i++) cout<<A[i]<<" ";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: