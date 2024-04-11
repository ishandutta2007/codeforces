#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack <char> a;
	string s;
	cin >> s;
	int n=s.size();
	for (int i = 0; i < n; i++)
	{
		if(!a.empty() && a.top()=='(' && s[i] == ')')a.pop();
		else a.push(s[i]);
	}
	cout << n-a.size();
}