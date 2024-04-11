#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	long long a,b,c;cin>>a>>b>>c;
	long long ans=c*2+min(a,b)*2;
	if (a!=b) ans++;cout<<ans;
}