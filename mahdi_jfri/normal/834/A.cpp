#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int main()
{
	char c1 , c2;
	cin >> c1 >> c2;
	int n;
	cin >> n;
	n %= 4;
	if(n == 2 || n == 0)
	{
		cout << "undefined";
		return 0;
	}
	if(c1 == '>')
	{
		if(n == 1)
		{
			if(c2 == 'v')
				cout << "cw";
			else
				cout << "ccw";
		}
		else
		{
			if(c2 == 'v')
				cout << "ccw";
			else
				cout << "cw";
		}
	}
	if(c1 == '<')
	{
		if(n == 1)
		{
			if(c2 == '^')
				cout << "cw";
			else
				cout << "ccw";
		}
		else
		{
			if(c2 == '^')
				cout << "ccw";
			else
				cout << "cw";
		}

	}
	if(c1 == '^')
	{
		if(n == 1)
		{
			if(c2 == '>')
				cout << "cw";
			else
				cout << "ccw";
		}
		else
		{
			if(c2 == '>')
				cout << "ccw";
			else
				cout << "cw";
		}

	}
	if(c1 == 'v')
	{
		if(n == 1)
		{
			if(c2 == '<')
				cout << "cw";
			else
				cout << "ccw";
		}
		else
		{
			if(c2 == '<')
				cout << "ccw";
			else
				cout << "cw";
		}

	}
}