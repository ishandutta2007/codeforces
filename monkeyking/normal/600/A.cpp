#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair 
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;
vector <string> vec,num,str;

bool isnum(string c)
{
	if(c=="") return false;
	rep(c.size())
	{
		if(!('0'<=c[i] && c[i]<='9')) return false;
	}
	if(c=="0") return true;
	return (c[0]!='0');
}

int main()
{
//	freopen("input.txt","r",stdin);
	string c;
	cin>>c;
	c+=';';
	int begin=0,len=0;
	rep(c.size())
	{
		len++;
		if(c[i]==',' || c[i]==';')
		{
			vec.push_back(c.substr(begin,len-1));
			len=0;
			begin=i+1;
		}
	}
//	cout<<vec.size()<<Endl;
	rep(vec.size())
	{
		if(isnum(vec[i])) num.push_back(vec[i]);else str.push_back(vec[i]);
	}
	if(num.size())
	{
		cout<<"\"";
		rep(num.size()-1)
		{
			cout<<num[i]<<',';
		}
		cout<<num[num.size()-1];
		cout<<"\"\n";
	}
	else
	{
		cout<<'-'<<endl;
	}
	if(str.size())
	{
		cout<<"\"";
		rep(str.size()-1)
		{
			cout<<str[i]<<',';
		}
		cout<<str[str.size()-1];
		cout<<"\"\n";
	}
	else
	{
		cout<<'-'<<endl;
	}
	return 0;
}