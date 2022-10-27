#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
vector <pair <pair <int, int>, int> > mass;
int add_sum(int a, int b)
{
	mass.push_back({{a, b}, 0});
	return a + b;
}
int add_xor(int a, int b)
{
	mass.push_back({{a, b}, 1});
	return (a ^ b);
}
int gcd1(int a, int b)
{
	a %= b;
	if(a <= 1)
	{
		return a;
	}
	return b - (b * gcd1(b, a) - 1) / a;
}
int mul(int a, int n)
{
	int add = 0;
	int add1 = a;
	for(int i = 0; (1LL << i) <= n; i++)
	{
		if(i != 0)
		{
		add_sum(add1, add1);
		add1 *= 2;
		}
		if((1LL << i) & n)
		{
			if(add == 0)
			{
				add = add1;
			}
			else
			{
				add_sum(add1, add);
				add += add1;
			}
		}
	}
	return add;
}
signed main()
{
 //   ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
   // cout.tie(NULL);
    int x;
    cin >> x;
	while(x != 1)
	{
		for(int i = 2; ; i *= 2)
		{
			add_sum((i / 2) * x, (i / 2) * x);
			if(((x * i) ^ x) % x == 0)
			{
				continue;
			}
			int y = add_xor(i * x, x);
			int g = __gcd(x, y);
			int a = mul(x, gcd1(x / g, y / g));
			int b = mul(y, (a - g) / y);
			int st = (1LL << 20);
			int q = (st - b % st) * gcd1(x, st) % st;
			int c = mul(x, q);
			x = add_xor(add_sum(a, c), add_sum(b, c));
			break;
		}
	}
	cout << mass.size() << "\n";
	for(int i = 0; i < mass.size(); i++)
	{
		cout << mass[i].first.first << " ";
		if(mass[i].second == 0)
		{
			cout << "+ ";
		}
		else
		{
			cout << "^ ";
		}
		cout << mass[i].first.second << "\n";
	}
    return 0;
}