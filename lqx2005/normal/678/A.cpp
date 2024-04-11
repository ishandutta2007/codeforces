#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
int main()
{
	cin>>n>>k;
	int x=n/k;
	x*=k;
	if(x<=n) x+=k;
	cout<<x<<endl;
	return 0;
}