#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int main()
{
	int T;cin>>T;
	while (T--)
	{
		int s=0,i,flg=0;cin>>a;
		for (i=0;i<a.length();i++)
		{
			if (a[i]=='A') s++;else s--;
			if (s<0) flg=1;
		}
		if (flg || a[a.length()-1]!='B') puts("NO");else puts("YES");
	}
}