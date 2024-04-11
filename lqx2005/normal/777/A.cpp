#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x;
int a[3];
int main()
{
	cin>>n>>x;
	n%=6;
	a[x]=1;
	for(int i=n;i>=1;i--)
	{
		if(i%2==1) swap(a[0],a[1]);
		else swap(a[1],a[2]);
	}
	if(a[0]) cout<<"0"<<endl;
	else if(a[1]) cout<<"1"<<endl;
	else cout<<"2"<<endl;
	return 0;
}