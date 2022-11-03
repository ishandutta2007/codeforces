#include <iostream>
#include <string>
using namespace std;

int findl(string a,int l,string b,int c)
{
	for (int i = l+1; i < a.size(); i++)
	{
		string d=a.substr(i,c);
		if(d==b)
		return i;
	}
	return -1;
}

int main()
{
	string a;
	cin>>a;
	int max=0;
	for(int i=0;i<a.size();i++)
	{
		for (int j = i; j-i+1 < a.size(); j++)
		{
			string b=a.substr(i,j-i+1);
			int l=i,k=findl(a,l,b,j-i+1);
			if(l != k && k!=-1)
			{
				if(max<j-i+1) 
				{max=j-i+1;}
			}
		}
	}
	cout<<max;
}