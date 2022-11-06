#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<set>
#include<string>
#define int long long
using namespace std;
int n,cnt;
string name[100];
set<string> number[100];;
inline bool check(string a,string b)
{
	int sa(a.size()),sb(b.size());
	if(sb>sa)
		return false;
	for(int i=1;i<=sb;i++)
		if(a[sa-i]!=b[sb-i])
			return false;
	return true;
}
signed main()
{
	set<string>::iterator it,del;
	int now,k;
	string tel,peo;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>peo;
		for(now=1;now<=cnt;now++)
			if(peo==name[now])
				break;
		if(now>cnt)
			name[++cnt]=peo;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>tel;
			for(it=number[now].begin();it!=number[now].end();)
			{
				if(check(tel,*it))
					del=it,it++,number[now].erase(del);
				else
					it++;
			}
			for(it=number[now].begin();it!=number[now].end();it++)
				if(check(*it,tel))
					break;
			if(it==number[now].end())
				number[now].insert(tel);
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		cout<<name[i]<<" "<<number[i].size()<<" ";
		for(it=number[i].begin();it!=number[i].end();it++)
			cout<<*it<<" ";
		cout<<endl;
	}
	return 0;
}