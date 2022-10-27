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
int n, A[1005], B[1005], C[1005];
int k1, k2;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k1>>k2;
	k1+=k2;
	for (int i=1; i<=n; i++) cin>>A[i];
	for (int i=1; i<=n; i++) cin>>B[i];
	for (int i=1; i<=n; i++) C[i]=abs(A[i]-B[i]);
	
	sort(C+1, C+(n+1));
	while (k1>0)
	{
		int i=n, l=C[n];
		if (l==0) break;
		
		while (C[i]==l)
		{
			C[i]--;
			k1--;
			i--;
			if (k1==0) break;
		}
 	}
	
	int ans=0;
	if (k1>0) ans=k1%2;
	else for (int i=1; i<=n; i++) ans+=C[i]*C[i];
	
	cout<<ans;
}