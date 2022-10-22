#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[2020];
int main()
{
	int n,i;cin>>n;cout<<n+1<<endl<<1<<' '<<n<<' '<<100000<<endl;
	for (i=1;i<=n;i++) cin>>a[i],a[i]+=100000;
	for (i=1;i<=n;i++) cout<<2<<' '<<i<<' '<<a[i]-i<<endl;
}