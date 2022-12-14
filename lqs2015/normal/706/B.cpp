#include<iostream>
#include<algorithm>
using namespace std;
int n,q,a[111111],x,low,high;
int main()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	cin>>q;
	while(q--)
	{
		cin>>x;
		cout<<upper_bound(a,a+n,x)-a<<endl;
	}
	return 0;
}