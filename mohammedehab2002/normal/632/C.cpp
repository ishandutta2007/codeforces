#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string a,string b)
{
	return (a+b<b+a);
}
int main()
{
	int n;
	cin >> n;
	string s[n];
	for (int i=0;i<n;i++)
	cin >> s[i];
	sort(s,s+n,cmp);
	for (int i=0;i<n;i++)
	cout << s[i];
}