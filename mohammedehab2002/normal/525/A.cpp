#include <iostream>
#include <ctype.h>
#include <string.h>
using namespace std;
int main()
{
	int n,i,x,ans=0,arr[26];
	string s;
	cin >> n >> s;
	for (i=0;i<26;i++)
	arr[i]=0;
	for (i=0;i<s.size();i+=2)
	{
		if (s[i]!=tolower(s[i+1]))
		{
			arr[s[i]-'a']++;
			if (arr[s[i+1]-'A']!=0)
			arr[s[i+1]-'A']--;
			else
			ans++;
		}
	}
	cout << ans;
}