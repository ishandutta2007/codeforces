#include<iostream>
#include<cstring>
#include<cstdio>
#define N 100010
#define ll long long
using namespace std;
int a[111];
int main()
{
	int n,i,k,mx=0,s=0;cin>>n;
	for (i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]),s+=a[i];
	for (k=mx;;k++)
	{
		int t=0;
		for (i=1;i<=n;i++) t+=k-a[i];
		if (t>s) {cout<<k;return 0;} 
	}
}