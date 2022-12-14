#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1111];
int main()
{
	cin>>n;
	for (int i=1;i<=2*n;i++)
	cin>>a[i];
	sort(a+1,a+2*n+1);
	if (a[n]==a[n+1]) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
}