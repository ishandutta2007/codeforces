#include <iostream>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	string s((n-k)/2+1,'1');
	s[s.size()-1]='0';
	while (s.size()<n)
	s+=s;
	cout << s.substr(0,n);
}