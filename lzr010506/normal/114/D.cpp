#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[2100], pp[2100];
string s, a, b;
ll dset[4000100];
vector<int> KMP(string s, string k) 
{
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i = 1; i < n; i ++) 
	{
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j]) j ++;
		pi[i] = j;
	}
	vector<int> res;
	for(int i = k.size() + 1; i < pi.size(); i ++)
		if(pi[i] == k.size())
			res.push_back(i - k.size() - k.size());
	return res;
}

int main()
{
	pp[0] = 1;
	for(int i = 1; i < 2100; i ++)
		pp[i] = pp[i - 1] * 31;
	int i, j, ND = 0;
	cin >> s >> a >> b;
	ll p = (ll)1;
	h[0] = (ll)(s[0] - 'a' + 1);
	for(i = 1; i < s.length(); i ++)
	{
		h[i] += h[i - 1] + (ll)(s[i] - 'a' + 1) * pp[i];
	}
	vector<int> p1 = KMP(a + "$" + s, a);
	vector<int> p2 = KMP(b + "$" + s, b);
	if(p1.size() == 0 || p2.size() == 0) printf("0");
	else
	{
		for(i = 0; i < p1.size(); i++)
			for(j = p2.size() - 1; j >= 0; j--)
			{
				if(p1[i] <= p2[j] && p1[i] + a.size() <= p2[j] + b.size())
				{
					ll left = 0;
					if(p1[i] > 0) left = h[p1[i] - 1];
					ll li = (h[p2[j] + b.size() - 1] - left) * pp[2050 - p1[i]];
					dset[ND] = li;
					ND++;
				}
				else break;
			}
		int  res = 0;
		if(ND > 0)
		{
			sort(dset, dset + ND);
			res = 1;
			for(i = 1; i < ND; i++)
				if(dset[i] != dset[i - 1])
					res++;
		}
		printf("%d", res);
	}
	return 0;
}