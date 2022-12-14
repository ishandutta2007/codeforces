#include<iostream>
#include<string>
using namespace std;
string s;
int n,ans;
int main()
{
	cin>>s>>n;
	int sz=s.size();
	for (int i=sz-1;i>=0;i--)
	{
		if (s[i]=='0') n--;
		else ans++;
		if (!n) break; 
	}
	if (!n) cout<<ans<<endl;
	else cout<<sz-1<<endl;
	return 0;
}