#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n;
string s,t;
int main()
{
	cin>>s;
	for (int i=1;i<=5;i++)
	{
		cin>>t;
		if (t[0]==s[0] || t[1]==s[1])
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return Accepted;
}