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
#define mn 100005
#define FLN "test"

int GCD(int a, int b)
{
	if (a%b==0) return b;
	return GCD(b, a%b);
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m, n;
	cin>>n>>m;
	
	vector <pair <int, int> > ans;
	ans.clear();
	
	for (int i=1; i<=n; i++) for (int j=i+1; j<=n; j++)
	{
		if (GCD(i, j)==1) ans.push_back({i, j});
		if (ans.size()>=m) break;
	}
	
	if (ans.size()<m || m<n-1) cout<<"Impossible";
	else 
	{
		cout<<"Possible\n";
		for (int i=0; i<m; i++) cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
}


// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: