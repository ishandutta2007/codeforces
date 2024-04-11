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

string SA, SB;
vector <string> V;

string pref(int A, int B)
{
	return (SA.substr(0, A)+SB.substr(0, B));
}

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	cin>>SA>>SB;
	for (int i=1; i<=SA.size(); i++) for (int j=1; j<=SB.size(); j++) V.push_back(pref(i, j));
	
	string ans=V[0];
	
	for (int i=1; i<V.size(); i++) ans=min(ans, V[i]);
	cout<<ans;
}