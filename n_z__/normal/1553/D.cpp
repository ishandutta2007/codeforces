#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
main()
{
    ios::sync_with_stdio(false),cin.tie(),cout.tie();
	int q;
	cin>>q;
	while(q--)
	{
        string s,t;
		cin>>s>>t;
		if((s.length()+t.length())%2==1)
		s=s.substr(1,s.length()-1);
		int now=0;
		for(int x=0;x<s.length();x++)
		{
			if(s[x]==t[now])now++;
			else x++;
		}
		if(now>=t.length())puts("Yes");
		else puts("No");
    }
}