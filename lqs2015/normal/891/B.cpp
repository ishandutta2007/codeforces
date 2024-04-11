#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
int n,a[55],b[55];
map<int,int> mp;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++) mp[a[i]]=a[i+1];
	mp[a[n]]=a[1];
	for (int i=1;i<=n;i++) cout<<mp[b[i]]<<" ";
	cout<<endl;
 }