#include<iostream>
#include<cstring>
using namespace std;
string s;
bool ispan(string a)
{
	int cnt = 0;
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] == a[a.size() - i - 1])
			cnt++;
		else
			return false;
	}
	if(cnt == a.size())
		return true;
}
int main()
{
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'A' || s[i] == 'W' || s[i] == 'O' || s[i] == 'X' || s[i] == 'V' || s[i] == 'T' || s[i] == 'Y' || s[i] == 'H' || s[i] == 'U')
			cnt++;
		if(s[i] == 'M' || s[i] == 'I')
			cnt++;
	}
	if(cnt == s.size())
	{
		if( ispan(s) )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}