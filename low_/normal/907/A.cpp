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

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	int af, am, as, ams;
	
	cin>>af>>am>>as>>ams;
	if (ams>=as && ams<=2*as && ams<af && ams<am) cout<<2*af<<"\n"<<2*am<<"\n"<<ams;
	else if (as>=ams && as<=ams*2) cout<<2*af<<"\n"<<2*am<<"\n"<<as;
	else cout<<-1;
}