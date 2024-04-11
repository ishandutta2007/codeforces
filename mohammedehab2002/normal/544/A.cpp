#include <iostream>
#include <string.h>
#include <set>
using namespace std;
int main()
{
	set <char> t;
	string s;
	int k,i,c=0,arr[26];
	cin >> k >> s;
	for (i=0;i<s.size();i++)
	t.insert(s[i]);
	if (t.size()<k)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	memset (arr,0,sizeof(arr));
	for (i=0;c<k-1;i++)
	{
		if (arr[s[i]-'a'])
		cout << s[i];
		else
		{
			if (c==0)
			cout << s[i];
			else
			cout << endl << s[i];
			arr[s[i]-'a']++;
			c++;
		}
	}
	while (arr[s[i]-'a'])
	{
		cout << s[i];
		i++;
	}
	if (k!=1)
	cout << endl << s.substr(i);
	else
	cout << s;
}