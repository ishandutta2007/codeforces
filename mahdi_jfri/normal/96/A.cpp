
 #include<iostream>
#include<string>
using namespace std;
bool check(string a,int j)
{
	for(int i=0;i<7;i++)
	{
		if(a[i]!=(j+48))
		return 0;
	}
	return 1;
}
int main()
{
	bool b=0;
	string a;
	cin>>a;
	for(;a.size()>0;)
	{
		int c=a[0]-48;
		b=check(a,c);
		if(b==0)
		a.erase(0,1);
		else {cout<<"YES"; return 0;}
	}
	cout<<"NO";
	
}