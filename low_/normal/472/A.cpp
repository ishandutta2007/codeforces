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

int IP[mn*10];

void eratos()
{
	IP[0]=0;
	IP[1]=0;
	for (int i=2; i<mn*10; i++) IP[i]=1;
	for (int i=2; i<mn*10; i++) if (IP[i]==1) for (int j=i; j*i<mn*10; j++) IP[i*j]=0;
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	eratos();
	cin>>n;
	for (int i=2; i<n-1; i++) if (!IP[i] && !IP[n-i])
	{
		cout<<i<<" "<<n-i;
		return 0;
	}
}