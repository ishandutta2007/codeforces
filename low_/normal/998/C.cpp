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

int n, x, y;
string S;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>x>>y>>S;
	
	int gr=(S[0]=='0');
	for (int i=0; i<S.size()-1; i++) if (S[i]=='1' && S[i+1]=='0') gr++;
	
	int ans=0;
	while (gr>1)
	{
		ans+=min(x, y);
		gr--;
	}
	
	if (gr==1) ans+=y;
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: