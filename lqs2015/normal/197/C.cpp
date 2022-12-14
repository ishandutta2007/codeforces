#include<iostream>
#include<set>
#include<string>
using namespace std;
struct ch
{
	char c;
	int ind;
	bool operator < (const ch &a) const
	{
		if (c!=a.c) return c>a.c;
		return ind<a.ind;
	}
	bool operator == (const ch &a) const
	{
		if (c==a.c && ind==a.ind) return 1;
		return 0;
	}
};
ch make(char c,int ind)
{
	ch a;
	a.c=c;a.ind=ind;
	return a;
}
set<ch> s;
set<pair<int,char> > se;
string str,ans;
int pre;
/*void print()
{
	for (set<ch>::iterator it=s.begin();it!=s.end();it++)
	{
		cout<<it->c<<" "<<it->ind<<endl;
	}
	cout<<endl;
	for (set<pair<int,char> >::iterator it=se.begin();it!=se.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<endl;
}*/
int main()
{
	cin>>str;
	for (int i=0;i<str.size();i++)
	{
		s.insert(make(str[i],i));
		se.insert(make_pair(i,str[i])); 
	}
	while(s.size())
	{
		set<ch>::iterator it=s.begin();
		ch u=*it;
		ans.push_back(it->c);
		for (int i=pre;i<str.size();i++)
		{
			set<pair<int,char> >::iterator it=se.find(make_pair(i,str[i]));
			se.erase(it);
			ch v=make(it->second,it->first);
			s.erase(s.find(v));
			if (v==u) 
			{
				pre=i+1;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}