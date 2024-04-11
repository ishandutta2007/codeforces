#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
#define inf 9223372036854775799
#define mn 100005

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	string S;
	cin>>n>>S;
	for (int i=0; i<S.size()-1; i++) if (S[i]==S[i+1] && S[i]!='?')
	{
		cout<<"No";
		return 0;
	}
	
	for (int i=0; i<S.size(); i++) if (S[i]=='?')
	{
		if (i==0 || i==S.size()-1) 
		{
			cout<<"Yes";
			return 0;
		}
		
		if (S[i-1]==S[i+1] || S[i-1]=='?' || S[i+1]=='?')
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
}