#include<iostream>
using namespace std;
int n,d,mx,l,f;
string s;
int main()
{
	cin>>n>>d;
	for (int i=0;i<d;i++)
	{
		cin>>s;
		f=0;
		for (int j=0;j<s.size();j++)
		{
			if (s[j]=='0') f=1;
		}
		if (f) l++;
		else 
		{
			mx=max(mx,l);
			l=0;
		}
	}
	mx=max(mx,l);
	cout<<mx<<endl;
	return 0;
}