#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1111111],k=0;
int main()
{
	cin>>n;k=1;
	for (int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	for (int i=0;i<n;i++)
	{
		if (a[i]<k)
		{
			k--;
		}
		k++;
	}
	cout<<k<<endl;
	return 0;
}