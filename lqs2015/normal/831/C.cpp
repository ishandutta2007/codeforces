#include<iostream>
#include<set>
#include<vector>
#include<cstdio>
using namespace std;
set<int> s,se,sp;
int k,n,a[2222],b[2222],x[2222],ans;
int main()
{
	scanf("%d%d",&k,&n);
	for (int i=1;i<=k;i++) 
	{
		scanf("%d",&a[i]);
		x[i]=x[i-1]+a[i];
	}
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&b[i]);
		se.insert(b[i]);
	}
	for (int i=1;i<=k;i++)
	{
		ans=b[1]-x[i];
		sp=se;
		for (int j=1;j<=k;j++)
		{
			set<int>::iterator it=sp.find(ans+x[j]);
			if (it!=sp.end()) sp.erase(it);
		}
		if (sp.empty()) s.insert(ans);
	}
	cout<<s.size()<<endl;
	return 0;
}