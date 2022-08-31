#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int a[10];
	for (int i=1;i<=4;++i)
		cin>>a[i];
	sort(a+1,a+5);
	int ans=0;
	for (int i=1;i<4;++i)
		if (a[i]==a[i+1]) ++ans;
	cout<<ans<<endl;
	return 0;
}