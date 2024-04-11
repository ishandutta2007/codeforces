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

int rev(int itg)
{
	int ret=itg, temp=itg, l=0;
	vector <int> v;
	v.clear();
	while (temp>0)
	{
		l++;
		v.push_back(temp%10);
		temp/=10;
	}
	for (int i=0; i<l; i++) 
	{
		ret*=10;
		ret+=v[i];
	}
	return ret;
	
}

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int k, p;
	cin>>k>>p;
	int ttl=0;
	
	for (int i=1; i<=k; i++) ttl=(ttl+rev(i))%p;
	
	cout<<ttl;
}