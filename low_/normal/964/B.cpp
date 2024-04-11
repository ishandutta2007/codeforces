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

int t[1005];

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, A, B, C, T;
	cin>>n>>A>>B>>C>>T;
	for (int i=1; i<=n; i++) cin>>t[i];
	
	if (B>=C) cout<<n*A;
	else
	{
		int tmp=0;
		for (int i=1; i<=n; i++) tmp+=t[i];
//		tmp=-tmp;
//		tmp+=n*T;
		tmp=n*T-tmp;
	//	cout<<tmp<<"\n";
		
		tmp*=C;
		tmp+=n*A;
		for (int i=1; i<=n; i++) tmp-=(T-t[i])*B;
		cout<<tmp;
	}
	
}