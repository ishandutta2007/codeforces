#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int i,res=0;
	string s,ans="hello";
	cin >> s;
	for (i=0;i<s.size();i++)
	{
		if (s[i]==ans[res])
		res++;
		if (res==5)
		{
			cout << "YES";
			exit(0);
		}
	}
	cout << "NO";
}