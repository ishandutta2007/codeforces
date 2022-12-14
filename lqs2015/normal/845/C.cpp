#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int eno,ent,n;
pair<int,int> tv[222222];
int main()
{
	eno=ent=-1e9;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d%d",&tv[i].first,&tv[i].second);
	sort(tv+1,tv+n+1);
	for (int i=1;i<=n;i++)
	{
		if (tv[i].first>eno) eno=tv[i].second;
		else if (tv[i].first>ent) ent=tv[i].second;
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}