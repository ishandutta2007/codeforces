#include<iostream>
#include<set>
using namespace std;
int a,b,c,d;
set<int> s;
int main()
{
	cin>>a>>b>>c>>d;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	s.insert(d);
	cout<<4-s.size()<<endl;
	return 0;    
 }