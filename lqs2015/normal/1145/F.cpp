#include<bits/stdc++.h>
using namespace std;
bool f[]={1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,1,0,1,1,1,1,1};
string s;
int n,cnt;
int main()
{
	cin>>s;
	n=s.size();
	for (int i=0;i<n;i++)
	{
		cnt+=f[s[i]-'A'];
	}
	if (cnt==0 || cnt==n) printf("YES\n");
	else printf("NO\n");
	return 0;
}