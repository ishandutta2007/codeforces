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


main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	IP[0]=1;
	IP[1]=1;
	for (int i=2; i<mn*10; i++) IP[i]=i;
	for (int i=2; i<mn*10; i++) if (IP[i]==i) for (int j=2; i*j<mn*10; j++) IP[i*j]=i;
	
	int T, pri;
	cin>>T;
	pri=T-IP[T]+1;
	
	int m=inf;
	for (int i=pri; i<=T; i++)
	{
		
		int pri2=i-IP[i]+1;
		if (pri2>=3) m=min(m, pri2);
	}
	
	cout<<m;
}