#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n;cin>>n;
	if(n%2) cout<<2*(n/2+1)*(n/2+2)<<endl;
	else cout<<(n/2+1)*(n/2+1)<<endl;
}