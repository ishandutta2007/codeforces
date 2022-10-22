#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(N) for(int i=0;i<N;i++)
using namespace std;
set <unsigned long long> table;

unsigned long long change(string c)
{
	unsigned long long ans=0LL;
	unsigned long long q=1LL;
	for(int i=c.size()-1;i>=0;i--)
	{
		if(c[i]=='1') ans+=q;
		q*=2;
	}
//	cout<<ans<<endl;
	return ans;
}

void dfs(string c,bool zero)
{
//	cout<<c<<endl;
//	system("pause");
	c+="0";
	unsigned long long krk=change(c);
	if(!zero)
	{
		if(krk>1000000000000000000) return;
		table.insert(krk);
		dfs(c,true);
	}
	c[c.size()-1]++;
	krk++;
//	cout<<c<<' '<<krk<<endl;
//	system("pause");
	if(krk>1000000000000000000) return;
	if(zero) table.insert(krk);
	dfs(c,zero);
}

int main()
{
	dfs("1",false);
	string c;
	unsigned long long a,b;
	cin>>a>>b;
//	for(int i=0;i<100;i++)
//	{
//		if(table.count(i)) cout<<i<<endl;
//	}
	set <unsigned long long>::iterator it=table.begin();
	int ans=0;
	for(;it!=table.end();it++)
	{
		if(a<=*it && *it<=b) ans++;
	}
	cout<<ans<<endl;
	return 0;
}