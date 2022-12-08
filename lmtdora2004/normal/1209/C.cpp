#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int f[20];
int l[20];
bool used[200005];
signed main()
{
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		cin>>n>>s;
		bool can=true;
		for(int br=0; br<=9; br++)
		{
			for(int i=0; i<n; i++)
			{
				used[i]=false;
			}
			int cmax=br;
			for(int i=0; i<s.size(); i++)
			{
				if(s[i]-'0'==cmax)
				{
					used[i]=true;
				}
				if(s[i]-'0'>cmax)
				{
					used[i]=true;
					cmax=s[i]-'0';
				}
			}
			int nmax=cmax;
			cmax=0;
			bool cann=true;
			for(int i=0; i<s.size(); i++)
			{
				if(used[i]) continue;
				if(s[i]-'0'<cmax)
				{
					cann=false;
					break;
				}
				cmax=max(cmax, s[i]-'0');
			}
			if(cann&&cmax<=br)
			{
				can=false;
				for(int i=0; i<n; i++)
				{
					cout<<1+used[i];
				}
				break;
			}
		}
		if(can)
		{
			cout<<'-';
		}
		cout<<endl;
	}
}