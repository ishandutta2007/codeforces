#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int i,e=0,pos;
    string s;
    cin >> s;
    for (i=0;i<s.size();i++)
    {
    	if ((int)(s[i]-'0')%2==0)
    	{
    		e++;
    		pos=i;
    	}
	}
	if (e==0)
	{
		cout << -1;
		return 0;
	}
	else if (e==1)
	{
		swap (s[pos],s[s.size()-1]);
		cout << s;
	}
	else
	{
		for (i=0;i<s.size();i++)
		{
			if ((int)(s[i]-'0')%2==0)
			{
				if (s[i]<s[s.size()-1])
				{
					swap (s[i],s[s.size()-1]);
					cout << s;
					return 0;
				}
				else
				pos=i;
			}
		}
		swap (s[pos],s[s.size()-1]);
		cout << s;
	}
}