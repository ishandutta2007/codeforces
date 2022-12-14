#include<iostream>
#include<string>
using namespace std;
string s,str[10],st;
int n,h,p,g,f;
string did(string s)
{
	while(s.size()<4)
	{
		s="0"+s;
	}
	return s;
}
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>s;
		f=0;p=0;g=0;st="";
		for (int i=0;i<s.size();i++)
		{
			if (s[i]==':')
			{
				if (s[i-1]==':') p=g+1;
				else
				{
					str[++g]=st;
					st="";
				}
			}
			else st+=s[i];
		}
		if (st.size()>0) str[++g]=st;
		h=8-g;
		for (int i=1;i<=g;i++)
		{
			if (i==p && !f)
			{
				for (int j=1;j<=h;j++)
				{
					cout<<"0000";
					if (j+i!=9) cout<<":";
				}
				i--;f++;
			}
			else 
			{
				cout<<did(str[i]);
				if (i!=g || (p>g)) cout<<":";
			}
		}
		if (p>g)
		{
			for (int j=1;j<=h;j++)
			{
				cout<<"0000";
				if (j!=h) cout<<":";
			}
		}
		cout<<endl;
	}
	return 0;
}