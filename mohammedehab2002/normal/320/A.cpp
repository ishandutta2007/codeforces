#include <iostream>
#include <string.h>
using namespace std;
bool b=false;
void solve(int x,string s)
{
	if (x==s.size())
	{
		b=true;
		return;
	}
	if (s[x]=='1')
	solve(x+1,s);
	if (s[x]=='1' && s[x+1]=='4')
	solve(x+2,s);
	if (s[x]=='1' && s[x+1]=='4' && s[x+2]=='4')
	solve(x+3,s);
}
int main()
{
	string s;
	cin >> s;
	solve(0,s);
	if (b)
	cout << "YES";
	else
	cout << "NO";
}