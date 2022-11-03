#include<iostream>
#include<sstream>
#include<math.h>
using namespace std;
int main()
{
	string a,b;
	int c;
	cin>>a>>b;
	c=a.size();
	for(int i=0;i<c;i++)
	{
		if(a[i]!=b[i])
		cout<<"1";
		else
		cout<<"0";
	}
}