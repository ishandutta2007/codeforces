#include <iostream>
using namespace std;
int main()
{
	int n,k;
	string s,ans="";
	cin >> n >> k >> s;
	for (int i=0;i<s.size();i++)
	{
		if ('z'-s[i]>=s[i]-'a')
		ans+='z',k-='z'-s[i];
		else
		ans+='a',k-=s[i]-'a';
		if (k<0 && ans[i]=='z')
		ans[i]+=k,k=0;
		else if (k<0 && ans[i]=='a')
		ans[i]-=k,k=0;
	}
	if (!k)
	cout << ans;
	else
	cout << -1;
}