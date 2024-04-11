#include<iostream>
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
	
	int T;
	cin>>T;
	if (T==0) cout<<0;
	else if (T%2==0) cout<<T+1;
	else cout<<((T+1)/2);
}