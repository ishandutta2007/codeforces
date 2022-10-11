#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int arr[4],i,ans=0;
	string s;
	for (i=0;i<4;i++)
	cin >> arr[i];
	cin >> s;
	for (i=0;i<s.size();i++)
	ans+=arr[s[i]-'1'];
	cout << ans;
}