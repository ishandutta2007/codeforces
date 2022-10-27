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
	
	int n, d, A[105];
	cin>>n>>d;
	for (int i=0; i<n; i++) cin>>A[i];
	
	sort(A, A+n);
	int ans=0;
	for (int i=0; i<n; i++)
	{
		int ptr=i;
		while (ptr<n)
		{
			if (A[i]+d<A[ptr]) break;
			ptr++;
		}
		ans=max(ans, ptr-i);
	}
	
	cout<<n-ans;
	
}