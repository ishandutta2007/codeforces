#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[5];
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	sort(a+1,a+5);
	if((a[1]+a[2])>a[3]||(a[1]+a[3])>a[4]||(a[2]+a[3])>a[4])
	{
		cout<<"TRIANGLE"<<endl;
		return 0;
	}
	if((a[1]+a[2])==a[3]||(a[1]+a[3])==a[4]||(a[2]+a[3])==a[4])
	{
		cout<<"SEGMENT"<<endl;
		return 0;
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}