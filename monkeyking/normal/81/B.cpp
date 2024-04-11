#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <map>
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

bool isnum(string c)
{
	for(int i=0;i<c.size();i++)
	{
		if(!isdigit(c[i])) return false;
	}
	return true;
}

int main()
{
//	freopen("input.txt","r",stdin);
	string c;
	getline(cin,c);
	vector <string> vec;
	for(int i=0;i<c.size();i++)
	{
//		cout<<i<<' ';
		if(c[i]==' ') continue;
		if(c[i]=='.') {vec.push_back("..."),i+=2;continue;}
		if(c[i]==',') {vec.push_back(",");continue;}
		int ti=i;
		for(i--;isdigit(c[++i]););
		vec.push_back(c.substr(ti,i-ti));
		i--;
//		cout<<i<<endl;
	}
	bool space=false;
	for(int i=0;i<vec.size()-1;i++)
	{
		if(isnum(vec[i]) && isnum(vec[i+1])) vec[i]+=' ';
	}
	for(int i=0;i<vec.size()-1;i++)
	{
		if(vec[i]==",") vec[i]+=' ';
	}
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i]=="..." && vec[i-1]!=", ") vec[i]=" ...";
	}
	rep(vec.size())
	{
		cout<<vec[i];
	}
	cout<<endl;
	return 0;
}