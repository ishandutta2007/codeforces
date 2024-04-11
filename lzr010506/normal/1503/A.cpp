#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;
	while(T--)
	{
		ll n, i, a0 = 0, a1 = 0;
		string a, b0, b1;
		b0 = "";
		b1 = "";
		cin >> n;
		stack<char> p1, p2;
		cin >> a;
		for(i = 0; i < n; ++i)
		{
			if(a[i] == '0')
				a0++;
			else
				a1++;
		}
		if(a0 % 2 || a1 % 2)
		{
			cout << "NO" << endl;
			continue;
		}
		if(a[0] != a[n-1] || a[0] != '1')
		{
			cout << "NO" << endl;
			continue;
		}
		ll k1 = 0;
		bool z = 0;
		for(i = 0; i < n; ++i)
		{
			if(a[i] == '1')
			{
				if(k1 < a1 / 2)
				{
					b0 += '(';
					b1 += '(';
					k1++;
				}
				else
				{
					b0 += ')';
					b1 += ')';
				}
			}
			else
			{
				if(!z)
				{
					b0 += '(';
					b1 += ')';
					z = 1;
				}
				else
				{
					b0 += ')';
					b1 += '(';
					z = 0;
				}
			}
		}
		cout << "YES" << endl;
		for(i = 0; i < n; ++i)
			cout << b0[i];
		cout << endl;
		for(i = 0; i < n; ++i)
			cout << b1[i];
		cout << endl;
	}
	return 0;
 }