#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll n,k,a[100005];
int main()
{
	cin>>n>>k;int i;ll as=0,nw=1;
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (i=1;i<=k;i++)
	{
		if (nw>n) {puts("0");continue;}
		while (max(a[nw]-as,0ll)==0 && nw<=n) nw++;
		if (nw>n) {puts("0");continue;}
		else cout<<a[nw]-as<<endl;
		as+=(a[nw]-as);
	}
}