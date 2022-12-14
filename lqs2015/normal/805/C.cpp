#include<iostream>
using namespace std;
int n;
int main()
{
	cin>>n;
	if (n%2) n++;
	cout<<n/2-1<<endl;
	return 0;
}