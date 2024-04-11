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
#define inf 100005
#define mn 100005
#define FLN "test"

int t, n, A[mn*10];
vector <pair <int, int> > V;

double SS(int a, int b)
{
	return (double)((a+b+a+b)*(a+b+a+b))/(double)(a*b);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1; i<=n; i++) cin>>A[i];
		A[0]=-1, A[n+1]=-1;
		sort(A+1, A+n+1);
		V={{0, 0}};
		for (int i=1; i<=n; i++) 
		{
			if (A[i]==V.back().first) V.back().second++;
			else if (A[i]==A[i-1] || A[i]==A[i+1]) V.push_back({A[i], 1});
		}
		bool b=1;
		for (int i=1; i<V.size(); i++) if (V[i].second>=4)
		{
			for (int j=0; j<4; j++) cout<<V[i].first<<' '; cout<<'\n';
			b=0;
			break;
		}
		
		if (!b) continue;
		
		int d=inf, r=0;
		for (int i=1; i<V.size()-1; i++) if (SS(V[i+1].first, V[i].first)<SS(d, r)) d=V[i+1].first, r=V[i].first;
		cout<<r<<' '<<r<<' '<<d<<' '<<d<<'\n';
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: