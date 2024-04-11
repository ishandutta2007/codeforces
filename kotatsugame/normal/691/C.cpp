#include<iostream>
using namespace std;
string x;
main()
{
	cin>>x;
	int c=0;
	while(c<x.size()&&x[c]!='.')c++;
	if(c==x.size())x+='.';
	string t=x.substr(0,c)+x.substr(c+1);
	int L=0;
	while(t[L]=='0')L++;
	int R=t.size()-1;
	while(t[R]=='0')R--;
	int d=c-L-1;
	if(L==R)cout<<t[L];
	else cout<<t[L]<<'.'<<t.substr(L+1,R-L);
	if(d!=0)cout<<'E'<<d;
	cout<<endl;
}