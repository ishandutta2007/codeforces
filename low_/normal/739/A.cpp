#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define int long long
#define mod 1000000009
#define inf 4444444444444444444
#define mn 150005
#define pii pair <int, int>
#define XX first
#define YY second

int n, m;
int l, r, M=inf;


signed main()
{
//#ifdef LOCAL
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
//#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	while (m--)
	{
		cin>>l>>r;
		M=min(M, r-l+1);
	}
	
	cout<<M<<"\n";
	for (int i=0; i<n; i++) cout<<i%M<<"\n";
	
}