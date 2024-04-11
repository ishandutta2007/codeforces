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

int n, m, A[105], B[105];


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>A[i]>>B[i];
	int bnd=0;
	for (int i=1; i<=n; i++)
	{
		if (bnd<A[i]) break;
		
		bnd=max(bnd, B[i]);
	}
	
	if (bnd>=m) cout<<"yes";
	else cout<<"no";
}