#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
int n,r,b,g;
string str;
int main()
{
	cin>>n;
	cin>>str;
	for (int i=0;i<str.size();i++)
	{
		if (str[i]=='R') r++;
		if (str[i]=='B') b++;
		if (str[i]=='G') g++;
	}
	if (r && b && g) cout<<"BGR"<<endl;
	else if (r && b)
	{
		if (b>=2)
		{
			if (r>=2) cout<<"BGR"<<endl;
			else cout<<"GR"<<endl;
		}
		else if (r>=2) cout<<"BG"<<endl;
		else cout<<"G"<<endl; 
	}
	else if (b && g)
	{
		if (b>=2)
		{
			if (g>=2) cout<<"BGR"<<endl;
			else cout<<"GR"<<endl;
		}
		else if (g>=2) cout<<"BR"<<endl; 
		else cout<<"R"<<endl;
	}
	else if (r && g)
	{
		if (r>=2)
		{
			if (g>=2) cout<<"BGR"<<endl;
			else cout<<"BG"<<endl;
		}
		else if (g>=2) cout<<"BR"<<endl; 
		else cout<<"B"<<endl;
	}
	else if (r) cout<<"R"<<endl;
	else if (b) cout<<"B"<<endl;
	else cout<<"G"<<endl;
	return 0;
}