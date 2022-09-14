#include<iostream>
using namespace std;
main()
{
	int n,a[100],m=0,s=0;cin>>n;
	for(int i=0;i<n;m=max(m,a[i++]))cin>>a[i];
	for(int i=0;i<n;i++)s+=m-a[i];
	cout<<s<<endl;
}