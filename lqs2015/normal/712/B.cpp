#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string s;
int x,lr,ud;
int main()
{
	cin>>s;
	if (s.size()%2)
	{
		cout<<-1<<endl;
		return 0;
	}
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='U') ud++;
		else if (s[i]=='D') ud--;
		else if (s[i]=='L') lr++;
		else lr--;
	}
	x=abs(ud)+abs(lr);
	if (x%2)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<x/2<<endl;
	return 0;
}