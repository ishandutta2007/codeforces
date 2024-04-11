#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
long long m,b[1<<17],a[1<<17];
main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=0;i<n-1;i++)a[i]=b[i+1]-b[i]-1;
	sort(a,a+n-1);
	long long ans=0;
	for(int i=0;i<n-k;i++)ans+=a[i];
	cout<<ans+n<<endl;
}