#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 62;

ll t[maxn] , shit[maxn];

ll g(string s , int len)
{
	int n = (int)s.size() + len;

	int m = s.size() , res = 0;

	memset(shit , 0 , sizeof shit);

	for(int i = 1; i < n; i++)
	{
		if(n % i)
			continue;

		bool f = 1;
		if(i <= m)
			for(int j = i; j < m; j++)
				if(s[j] != s[j - i])
					f = 0;

		if(!f)
			continue;

		if(i > m)
			shit[i] = t[i - m];
		else
			shit[i] = 1;
		
		for(int j = 1; j < i; j++)
			if(i % j == 0)
				shit[i] -= shit[j];

		res += shit[i];

	}

	return res;
}

ll f(ll r)
{
	if(!r)
		return 0;

	bool f = 0;

	string s;

	ll res = 0;

	for(int i = maxn - 1; i >= 0; i--)
	{
		if(bit(r , i))
		{
			if(f)
				s += '0' , res += g(s , i) , s.pop_back();
			else
				for(int j = i - 1; j >= 0; j--)
					res += g("1" , j);

			f = 1;
		}

		if(f)
			s += '0' + bit(r , i);
	}

	res += g(s , 0);

	return res;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for(int i = 0; i < maxn; i++)
		t[i] = (1LL << i);

	ll l , r;
	cin >> l >> r;

	cout << f(r) - f(l - 1) << endl;
}
/*

0 0 1 1 1 1 2 2 2 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6 7 7 7 8 8 8 8 8 8 8 8 8 9 9 9 9 9 9 9 9 9 10 10 
0 0 1 1 1 1 2 2 2 3 3 3 3 3 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6 7 7 7 8 8 8 8 8 8 8 8 8 9 9 9 9 9 9 9 9 9 10 10 

*/