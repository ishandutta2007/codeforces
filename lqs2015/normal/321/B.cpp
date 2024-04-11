#include<iostream>
#include<string>
#include<queue>
#include<set>
using namespace std;
priority_queue<int> atk,atkk,atkkk;
priority_queue<int> pp,def,ppp,deff,defff,pppp;
int n,m,x,ans,y,anss,ansss;
string s;
multiset<int> ss,sss;
int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s>>x;
		if (s[0]=='A') atk.push(-x); 
		else def.push(x); 
		if (s[0]=='A') atkk.push(x);
		else deff.push(x); 
		if (s[0]=='A') atkkk.push(x);
		else defff.push(x); 
	}
	for (int i=1;i<=m;i++)
	{
		cin>>x;
		pp.push(x); 
		ppp.push(x);
		sss.insert(x); 
	}
	while(!pp.empty() && !atk.empty())
	{
		x=pp.top();y=-atk.top();
		if (x>=y) ans+=(x-y);
		else break;
		pp.pop();atk.pop();
	}
	if (!pp.empty() && atk.empty())
	{
		while(!pp.empty())
		{
			x=pp.top();
			ss.insert(x);pp.pop(); 
		}
		while(!def.empty() && !ss.empty())
		{
			x=def.top();
			set<int>::iterator it=ss.lower_bound(x+1);
			if (it==ss.end()) break;
			ss.erase(it);
			def.pop();
		}
		for (multiset<int>::iterator it=ss.begin();it!=ss.end();it++)
		{
			if (def.empty()) ans+=*it;
		}
	}
	while(!ppp.empty() && !atkk.empty())
	{
		x=ppp.top();y=atkk.top();
		if (x>=y) anss+=(x-y);
		else break;
		ppp.pop();atkk.pop();
	}
	if (!ppp.empty() && atkk.empty())
	{
		ss.clear();
		while(!ppp.empty())
		{
			x=ppp.top();
			ss.insert(x);ppp.pop(); 
		}
		while(!deff.empty() && !ss.empty())
		{
			x=deff.top();
			set<int>::iterator it=ss.lower_bound(x+1);
			if (it==ss.end()) break;
			ss.erase(it);
			deff.pop(); 
		}
		for (multiset<int>::iterator it=ss.begin();it!=ss.end();it++)
		{
			if (deff.empty()) anss+=*it;
		}
	}
	while(!defff.empty())
	{
		x=defff.top();
		multiset<int>::iterator it=sss.lower_bound(x+1);
		if (it==sss.end()) break;
		sss.erase(it);  
		defff.pop();
	}
	if (defff.empty())
	{
		while(!atkkk.empty())
		{
			x=atkkk.top();
			multiset<int>::iterator it=sss.lower_bound(x);
			if (it==sss.end()) break;
			ansss+=(*it-x);
			atkkk.pop();
			sss.erase(it);
		}
		if (atkkk.empty())
		{
			for (multiset<int>::iterator it=sss.begin();it!=sss.end();it++)
			{
				ansss+=*it;
			}
		}
	}
	cout<<max(max(ans,anss),ansss)<<endl;
	return 0;
}