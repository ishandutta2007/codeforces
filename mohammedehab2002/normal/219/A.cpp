#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int k,arr[26];
	string s,ans="";
	cin >> k >> s;
	memset(arr,0,sizeof(arr));
	for (int i=0;i<s.size();i++)
	arr[s[i]-'a']++;
	for (int i=0;i<26;i++)
	{
		if (arr[i]%k)
		{
			cout << -1;
			return 0;
		}
		string tmp(arr[i]/k,i+'a');
		ans+=tmp;
	}
	for (int i=0;i<k;i++)
	cout << ans;
}