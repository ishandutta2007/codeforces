#include <iostream>
using namespace std;
long long arr[2][2],e,o;
int main()
{
	string s;
	cin >> s;
	for (int i=0;i<s.size();i++)
	{
		arr[s[i]-'a'][i%2]++;
		e+=arr[s[i]-'a'][!(i%2)];
		o+=arr[s[i]-'a'][i%2];
	}
	cout << e << ' ' << o;
}