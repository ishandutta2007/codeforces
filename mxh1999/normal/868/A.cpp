#include<bits/stdc++.h>
using namespace std;

string s,a[110];
int n;

int main()
{
	cin>>s;
	cin>>n;
	bool bo=false;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==s)	bo=true;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (a[i][1]==s[0] && a[j][0]==s[1])	bo=true;
	if (bo)	printf("YES\n");else printf("NO\n");
}