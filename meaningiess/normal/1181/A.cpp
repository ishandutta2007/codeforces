#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll a,b,c;cin>>a>>b>>c;
	cout<<a/c+b/c+(a%c+b%c)/c<<' '<<((c-a%c)>(b%c)?0:min(min(a%c,c-a%c),min(b%c,c-b%c)));
}