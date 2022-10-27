#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	int n;
	string s;
	cin >> n >> s;
	int a = 0, b = 0,c = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
		{
			a++;
		}
		else if(s[i] == '1')
		{
			b++;
		}
		else
		{
			c++;
		}
	}
	int a1 = 0, b1 = 0, c1 = 0;
	for(int i = 0; i < n; i++)
	{
		if(a < n / 3)
		{
			if(s[i] == '1')
			{
				if(b > n / 3)
				{
					s[i] = '0';
					b--;
					a++;
				}
			}
			else if(s[i] == '2')
			{
				if(c > n / 3)
				{
					c--;
					a++;
					s[i] = '0';
				}
			}
		}
	}
	int a2 = 0, b2 = 0, c2 = c;
	for(int i = 0; i < n; i++)
	{
		if(b < n / 3)
		{
		if(s[i] == '0')
		{
			a1++;
			if(a1 > n / 3)
			{
				b++;
				s[i] = '1';
			}
		}
		else if(s[i] == '2')
		{
			if(c > n / 3)
			{
				s[i] = '1';
				c--;
				b++;
			}
		}
	}
	}
	a = 0, b = 0, c = 0;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '0')
		{
			a++;
		}
		else if(s[i] == '1')
		{
			b++;
		}
		else
		{
			c++;
		}
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if(c < n / 3)
		{
		if(s[i] == '0')
		{
			if(a > n / 3)
			{
				c++;
				a--;
				s[i] = '2';
			}
		}
		else if(s[i] == '1')
		{
			if(b > n / 3)
			{
				c++;
				b--;
				s[i] = '2';
			}
		}
	}
	}
	
	cout << s;
	return 0;
}