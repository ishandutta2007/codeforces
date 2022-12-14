#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int n1,n2;
int main()
{
	cin>>s1>>s2;
	n1=s1.size();
	n2=s2.size();
	if (s1!=s2) cout<<max(n1,n2)<<endl;
	else cout<<-1<<endl;
	return 0;
}