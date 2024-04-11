#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005

int p, y;
vector <int> primes;
int IP[mn];

void eratos()
{
	IP[1]=0;
	IP[0]=0;
	for (int i=2; i<mn; i++) IP[i]=1;
	for (int i=2; i<mn; i++) if (IP[i]) 
	{
		for (int j=i; j*i<mn; j++) IP[i]=0;
		primes.push_back(i);
	}
}

main()
{
	eratos();
	cin>>p>>y;
	
	int ans=y;
	
	while (ans>p)
	{
//		cout<<ans<<" "<<p<<"\n";
		bool k=true;
		for (int i=0; primes[i]*primes[i]<=min(p*p, ans); i++) if (ans%primes[i]==0) 
		{
			k=false;
			break;
		}
		if (k)
		{
			cout<<ans;
			return 0;
		}
		ans--;
		
	}
	
	cout<<-1;
}