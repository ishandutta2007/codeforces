#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> e[505];
int main()
{
	int n,m,i;cin>>n>>m;
	char c[505]={};
	for (i=1;i<=m;i++) c[i]='0';
	for (i=1;i<=m;i++)
	{
		c[i]='1';
		cout<<"? "<<c+1<<endl;fflush(stdout);
		c[i]='0';
		cin>>e[i].first;e[i].second=i;
	}
	sort(e+1,e+m+1);
	int s=0,tp;
	for (i=1;i<=m;i++)
	{
		c[e[i].second]='1';
		cout<<"? "<<c+1<<endl;fflush(stdout);
		cin>>tp;
		if (tp==s+e[i].first) {s=tp;continue;}
		c[e[i].second]='0';
	}
	cout<<"! "<<s<<endl;
}