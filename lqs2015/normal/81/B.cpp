#include<iostream>
#include<string>
using namespace std;
string s,ans;
int j;
char last(string &s)
{
	int sz=s.size();
	return s[sz-1];
}
int main()
{
	getline(cin,s);
	int n=s.size();
	for (int i=0;i<n;i++)
	{
		char c=s[i];
		if (c==' ') continue;
		else if (c==',') 
		{
			ans+=c;
			if (i!=n-1) ans+=' '; 
		}
		else if (c=='.') 
		{
			if (i==0 || last(ans)==' ') 
			{
				for (int j=i;j<=i+2;j++) ans+=s[j];
				i+=2;
				continue;
			}
			ans+=' ';
			for (int j=i;j<=i+2;j++) ans+=s[j];
			i+=2;
		}
		else
		{
			for (j=i;isdigit(s[j]);j++) ans+=s[j];
			i=j-1;
			while(s[j]==' ') j++;
			if (isdigit(s[j])) ans+=' ';
		}
	}
	cout<<ans<<endl;
	return 0;
}