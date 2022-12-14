#include<iostream>
using namespace std;
long long n,m,l,r,mid,cnt;
bool f;
int main()
{
	cin>>n>>m;
	if (n==1) 
	{
		cout<<1<<endl;
		return 0;
	}
	if (n<=m+1)
	{
		cout<<n<<endl;
		return 0;
	}
	n=n-m-1;
	l=m;r=m+1e10;
	while(l<=r)
	{
		mid=(l+r)/2;
		cnt=(2+mid-m)*(mid-m-1)/2;
		if (cnt>=n) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}