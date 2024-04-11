#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int i,x,j;
	vector <int> a(1,9),b(1,9);
	string s[8];
	for (i=0;i<8;i++)
	{
		s[i].resize(8);
		cin >> s[i];
	}
	for (i=1;i<7;i++)
	{
		for (x=0;x<8;x++)
		{
			if (s[i][x]=='W')
			{
				bool o=false;
				for (j=i-1;j>=0;j--)
				{
					if (s[j][x]!='.')
					{
						o=true;
						goto out;
					}
				}
				out: if (!o)
				a.push_back(i);
			}
			else if (s[i][x]=='B')
			{
				bool o=false;
				for (j=i+1;j<8;j++)
				{
					if (s[j][x]!='.')
					{
						o=true;
						goto out2;
					}
				}
				out2: if (!o)
				b.push_back(8-i-1);
			}
		}
	}
	if(*min_element(a.begin(),a.end())<=*min_element(b.begin(),b.end()))
	cout << 'A';
	else
	cout << 'B';
}