#include<iostream>
using namespace std;
int main()
{
	long long s;
	cin>>s;
	if (s%2) cout<<s/2-s;
	else cout<<s/2;
	return 0;
}