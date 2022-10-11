#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int k;
	string s;
	cin >> k >> s;
	sort(s.begin(),s.end());
	int sum=0;
	for (int i=0;i<s.size();i++)
	sum+=s[i]-'0';
	for (int i=0;i<s.size();i++)
	{
		if (sum>=k)
		{
			cout << i;
			return 0;
		}
		sum+='9'-s[i];
	}
	cout << s.size();
}