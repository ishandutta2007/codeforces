#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int i,x,j;
	string s,a="00";
	cin >> s;
	a+=s;
	for (i=0;i<a.size();i++)
	{
		for (x=i+1;x<a.size();x++)
		{
			for (j=x+1;j<a.size();j++)
			{
				string test="";
				test+=a[i];
				test+=a[x];
				test+=a[j];
				if (atoi(test.c_str())%8==0)
				{
					cout << "YES" << endl << atoi(test.c_str());
					return 0;
				}
			}
		}
	}
	cout << "NO";
}