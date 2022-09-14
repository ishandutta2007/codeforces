#include<iostream>
using namespace std;
string s;
int main()
{
	cin>>s;
	int a=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u')
		{
			a++;
			if(a>=3)
			{
				if(s[i-2]==s[i-1]&&s[i-1]==s[i])
				{
					a--;
				}
				else
				{
					cout<<' ';
					a=1;
				}
			}
		}
		else a=0;
		cout<<s[i];
	}
	cout<<endl;
}