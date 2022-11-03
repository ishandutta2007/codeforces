#include<iostream>
using namespace std;
int main()
{
	string a;
	cin>>a;
	if(a[0]>=97)
	a[0]=a[0]-'a'+'A';
	cout<<a;
}