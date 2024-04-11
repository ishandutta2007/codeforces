#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
const int N=2e5+5;
	
const double pi=acos(-1);
signed main()
{
	int n,k;
	cin>>n>>k;
	if(k>100000)return cout<<"No",0;
	for(int i=1;i<=k;++i)
	{
		if((n+1)%i) return cout<<"No",0;
	}
	cout<<"Yes";
}