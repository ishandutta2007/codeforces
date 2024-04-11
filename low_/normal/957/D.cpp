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

int n, M[mn], V[mn];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for (int i=1; i<=n; i++) cin>>M[i];
	
	V[0]=0;
	for (int i=1; i<=n; i++) V[i]=max(V[i-1], M[i]);
	V[n+1]=V[n];
	for (int i=n; i>0; i--) V[i]=max(V[i], V[i+1]-1);
	
	int ans=0;
	for (int i=1; i<=n; i++) ans+=(V[i]-M[i]);
	cout<<ans;
}