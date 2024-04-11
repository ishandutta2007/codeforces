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


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	char S[10005];
	cin>>n>>m;
	
	for (int i=1; i<=n; i++) cin>>S[i];
	int l, r;
	char c1, c2;
	for (int j=0; j<m; j++)
	{
		cin>>l>>r>>c1>>c2;
		for (int i=l; i<=r; i++) if (S[i]==c1) S[i]=c2;
	}
	for (int i=1; i<=n; i++) cout<<S[i];
}