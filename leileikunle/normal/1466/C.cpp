#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.size();
		int cnt = 0;
		for(int i=1;i<n;i++)
		{
			if(s[i]==s[i-1] || (s[i]==s[i-2] && i>1))
			{
				s[i] = '?';
				cnt++;
			}
		}
		cout<<cnt<<endl;
    }
}