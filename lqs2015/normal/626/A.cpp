#include<iostream>
#include<string>
using namespace std;
int n,x,y,ans;
string str,s;
void go(char c)
{
	if (c=='U') x--;
	if (c=='D') x++;
	if (c=='R') y++;
	if (c=='L') y--;
}
int main()
{
	cin>>n;
	cin>>str;
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<n-i+1;j++)
		{
			s=str.substr(j,i);
			x=0;y=0;
			for (int k=0;k<s.size();k++)
			{
				go(s[k]);
			} 
			if (x==0 && y==0) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}