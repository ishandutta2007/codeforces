#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n,m,a; cin>>n>>m>>a;
	int sum1,sum2 = 0;
	if(n%a) sum1 = n/a+1;
	else sum1 = n/a;
	if(m%a) sum2 = m/a+1;
	else sum2 = m/a;        
	cout<<sum1*sum2;
}