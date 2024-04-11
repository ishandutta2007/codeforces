#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100100
using namespace std;
int n,m,h[MAXN],ans;
int main()
{
	cin>>n;int a,t,i;
	for (i=1;i<=n;i++)
	{
		cin>>t;
		while (t--) cin>>a,h[a]++;
	}
	for (i=1;i<=100;i++) if(h[i]==n) cout<<i<<" ";
}