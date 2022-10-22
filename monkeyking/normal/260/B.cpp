#include <iostream>
#include <string>
#include <map>
#include <string.h>
#include <set> 
using namespace std;
int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
map <string,int> mp;

bool is(string c)
{
	string d=c.substr(0,2);
	bool type[]={false,false,true,false,false,true,false,false,false,false};
	if(!(c[2]=='-' && c[5]=='-')) return false;
	for(int i=0;i<10;i++)
	{
		if(type[i] || c[i]!='-') continue;
		return false;
	}
	string m=c.substr(3,2);
	string y=c.substr(6,4);
//	cout<<d<<' '<<m<<' '<<y<<endl;
	if(y!="2013" && y!="2014" && y!="2015") return false;
	int mm=(m[0]-'0')*10+m[1]-'0';
//	if(m[0]>'9' || m[1]>'9' || m[0]<'0' || m[1]<'0') return false;
//	cout<<"now:"<<d[0]<<' ';
	int dd=(d[0]-'0')*10+d[1]-'0';
//	cout<<dd<<endl;
	if(d[0]>'9' || d[1]>'9' || d[0]<'0' || d[1]<'0') return false;
//	cout<<d[0]+d[1]<<endl;
	if(dd>0 && dd<=month[mm]) return true;else return false;
}

int main()
{
	set <string> squ;
	string c;
	cin>>c;
	for(int i=0;i<c.size()-9;i++)
	{
		string t=c.substr(i,10);
		if(is(t)) mp[t]++;
	}
//	string maxk;
	int maxn=0;
	string maxs;
	for(map <string,int>::iterator it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>maxn) maxn=it->second,maxs=it->first;
	}
	cout<<maxs<<endl;
	return 0;
}