#include<iostream>

using namespace std;

int main()
{
	int k,r;
	cin>>k>>r;
	int i=1;
	while((k*i)%10!=r&&(k*i)%10!=0)i++;
	cout<<i<<endl;return 0;
}