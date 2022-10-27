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
	
	int n; string S;
	cin>>n>>S;
	
	int x, y; bool kingdom;
	
	x=(int)(S[0]=='R');
	y=(int)(S[0]=='U');
	kingdom=(bool)y;
	
	int ans=0;
	for (int i=1; i<S.size(); i++) 
	{
	//	cout<<kingdom;
		if (S[i]=='R') x++;
		else y++;
		
		if ((x-y>0 && kingdom) || (x-y<0 && !kingdom)) 
		{
			ans++;
			kingdom=!kingdom;
		}
	}
	
	cout<<ans;
}