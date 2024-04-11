#include<bits/stdc++.h> 

using namespace std; 
#define int long long
main() { 
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int sum = 0;
	if(a > b)
	{
		swap(a, b);
	}
	if(a > c)
	{
		swap(a, c);
	}
	if(b > c)
	{
		swap(b, c);
	}
	if(b - a >= d)
	{
		if(c - b >= d)
		{
			cout << 0;
		}
		else
		{
			cout << d - c + b;
		}
	}
	else if(c - b >= d)
	{
		cout << d - b + a;
	}
	else
	{
		sum = 2 * d - c + a;
		if(b < (c + a - sum) / 2)
		{
			cout << sum - b + (c + a - sum) / 2;
		}
		else if(b == (c + a - sum) / 2)
		{
			cout << sum;
		}
		else if(b > (c + a + sum) / 2)
		{
			cout << sum + b - (a + c + sum ) / 2;
		}
		else if(b == (c + a + sum) / 2)
		{
			cout << sum;
		}
		else
		{
			cout << sum;
		}
	}
	return 0;
}