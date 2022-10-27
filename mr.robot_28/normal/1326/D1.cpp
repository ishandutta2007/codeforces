#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 1;
vector <int> hash1, hash2, hash3, hash4;
const int const1 = 1e9 + 7;
const int const2 = 1e9 + 37;
vector <int> T1, T2;
int n;
pair <int, int>  get_hash1(int l, int r)
{
	if(l == 0)
	{
		return {hash1[r], hash2[r]};
	}
	else
	{
		return {(hash1[r] - hash1[l - 1] * T1[r - l + 1] % const1 + const1) % const1,
		(hash2[r] - hash2[l - 1] * T2[r - l + 1] % const2 + const2) % const2};
	}
}
pair <int, int> get_hash2(int l, int r)
{
	if(r == n - 1)
	{
		return {hash3[l], hash4[l]};
	}
	else
	{
		return {(hash3[l] - hash3[r + 1] * T1[r - l + 1] % const1 + const1) % const1,
		(hash4[l] - hash4[r + 1] * T2[r - l + 1] % const2 + const2) % const2};
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	T1.resize(1e6 + 1);
	T2.resize(1e6 + 1);
	T1[0] = 1;
	T2[0] =1;
	for(int i = 1; i <= 1e6; i++)
	{
		T1[i] = T1[i - 1] * 27 % const1;
		T2[i] = T2[i - 1] * 27 % const2;
	}
	while(t--)
	{
		string s;
		cin >> s;
		n = s.size();
		hash1.resize(n);
		hash2.resize(n);
		hash3.resize(n);
		hash4.resize(n);
		for(int i = 0; i < s.size(); i++)
		{
			if(i == 0)
			{
				hash1[i] = hash2[i] = s[i] - 'a' + 1;
			}
			else
			{
				hash1[i] = (hash1[i - 1] * 27 + s[i] - 'a' + 1) %const1;
				hash2[i] = (hash2[i - 1] * 27 + s[i] - 'a' + 1) % const2;
			}
		}
		for(int i = n - 1; i >= 0; i--)
		{
			if(i == n - 1)
			{
				hash3[i] = hash4[i] = s[i] - 'a' + 1;
			}
			else
			{
				hash3[i] = (hash3[i + 1] * 27 + s[i] - 'a' + 1) % const1;
				hash4[i] = (hash4[i + 1] * 27 + s[i] - 'a' + 1) % const2;
			}
		}
		vector <int> pal1(n), pal2(n);
		for(int i = 0; i < n; i++)
		{
			int l = 1, r = min(i + 1, n - i) + 1;
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(get_hash1(i - midd + 1, i) == get_hash2(i, i + midd - 1))
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			pal1[i] = l;
			l = 0, r = min(i + 1, n - i - 1) + 1;
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(get_hash1(i - midd + 1, i) == get_hash2(i + 1, i + midd))
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			pal2[i] = l;
		}
		int i = 0;
		while(i < s.size() / 2 && s[i] == s[n - i - 1])
		{
			i++;
		}
		int leftmax = i;
		int rightmax = i;
		int sumlen = 0;
		if(i * 2 != n)
		{
		for(int j = i; j < n - i; j++)
		{
			if(j - pal1[j] < i)
			{
				int len = min(j - i + 1, n - i - j);
				if(j - len < i && len * 2 - 1 > sumlen)
				{
					sumlen = len * 2  - 1;
					leftmax = i + len * 2 - 1;
					rightmax = i;
				}
			}
			if(j - pal2[j] < i)
			{
				int len = min(j - i + 1, n - i - 1 - j);
				if(j - len < i && len * 2 > sumlen)
				{
					sumlen = len * 2;
					leftmax = i + 2 * len;
					rightmax = i;
				}
			}
			if(j + pal1[j]  >= n - i)
			{
				int len = min(j - i + 1, n - i - j); 
				if(j + len >= n - i && len * 2 - 1 > sumlen){
					sumlen = len * 2 - 1;
					rightmax = i + len * 2 - 1;
					leftmax = i;
				}
			}
			if(j + pal2[j] + 1 >= n - i)
			{
				int len = min(j - i + 1, n - i - j - 1);
				if(j + len + 1 >= n - i && len * 2 > sumlen)
				{
					sumlen = len * 2;
					rightmax = i + 2 * len;
					leftmax = i;
				}
			}
		}
		}
		for(int j = 0; j < leftmax; j++)
		{
			cout << s[j];
		}
		for(int j = n - rightmax; j < n; j++)
		{
			cout << s[j];
		}
		cout << "\n";
	}
	return 0;
}