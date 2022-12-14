#include<iostream>
#include<string>
#include<set>
using namespace std;
string s;
set<string> a,b;
int n,m,num;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		a.insert(s); 
	}
	for (int i=1;i<=m;i++)
	{
		cin>>s;
		b.insert(s);
	}
	for (set<string>::iterator it=a.begin();it!=a.end();it++)
	{
		s=*it;
		if (b.find(s)!=b.end()) num++;
	}
	if (num&1) m--;
	if (n>m) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}