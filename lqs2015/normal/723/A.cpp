#include<iostream>
#include<algorithm>
using namespace std;
int x,y,z;
int main()
{
	cin>>x>>y>>z;
	int mx=max(x,max(y,z));
	int mn=min(x,min(y,z));
	cout<<mx-mn<<endl;
	return 0;
 }