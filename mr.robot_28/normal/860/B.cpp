#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > hash1, hash2;
const int const1 = 998244353;
const int const2 = 1e9 + 7;
vector <int> Pow1(11), Pow2(11);
pair <int, int> get_hash(int i, int j, int k)
{
	if(j == 0)
	{
		return {hash1[i][k], hash2[i][k]};
	}
	else
	{
		return {(hash1[i][k] - hash1[i][j - 1] * Pow1[k - j + 1] % const1 + const1) % const1, 
		(hash2[i][k] - hash2[i][j - 1] * Pow2[k - j + 1] % const2 + const2) % const2};
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	Pow1[0] = Pow2[0] = 1;
	for(int i = 1; i <= 10; i++)
	{
		Pow1[i] = Pow1[i - 1] * 11 % const1;
		Pow2[i] = Pow2[i - 1] * 11 % const2;
	}
	hash1.resize(n, vector <int> (9));
	hash2.resize(n, vector <int> (9));
	vector <string> s(n);
	vector <pair <int, int> > hashes;
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
		for(int j = 0; j < s[i].size(); j++)
		{
			if(j == 0)
			{
				hash1[i][j] = hash2[i][j] = s[i][j] - '0' + 1;
			}
			else
			{
				hash1[i][j] = (hash1[i][j - 1] * 11 + s[i][j] - '0' + 1) % const1;
				hash2[i][j] = (hash2[i][j - 1] * 11 + s[i][j] - '0' + 1) % const2;
			}
		}
		for(int j = 0; j < s[i].size(); j++)
		{
			for(int k = j; k < s[i].size(); k++)
			{
				hashes.push_back(get_hash(i, j, k));
			}
		}
	}
	vector <int> ans(n, 1e9);
	sort(hashes.begin(), hashes.end());
	for(int i = 0; i < n; i++)
	{
		vector <pair <int, pair <pair <int, int>, int> > > hashes1;
		for(int j = 0; j < s[i].size(); j++)
		{
			for(int k = j; k < s[i].size(); k++)
			{
				hashes1.push_back({k - j + 1, {get_hash(i, j, k), j}});
			}
		}
		sort(hashes1.begin(), hashes1.end());
		int st = - 1;
		for(int j = 0; j < hashes1.size(); j++)
		{
			int k = j;
			while(k < hashes1.size() && hashes1[k].second.first == hashes1[j].second.first )
			{
				k++;
			}
			int l = -1, r = hashes.size();
			int l1 = 0, r1 = hashes.size();
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(hashes[midd].first < hashes1[j].second.first.first || hashes[midd].first == hashes1[j].second.first.first && hashes[midd].second <hashes1[j].second.first.second)
				{
					l = midd;
				}
				else
				{
					r = midd;
				}
			}
			while(r1 - l1 > 1)
			{
				int midd = (r1 + l1) / 2;
				if(hashes[midd].first < hashes1[j].second.first.first || hashes[midd].first == hashes1[j].second.first.first && hashes[midd].second <= hashes1[j].second.first.second)
				{
					l1 = midd;
				}
				else
				{
					r1 = midd;
				}
			}
			if(l1 - l == k - j && ans[i] > hashes1[j].first)
			{
				st = hashes1[j].second.second;
				ans[i] = min(ans[i], hashes1[j].first);
			}
			j = k - 1;
		}
		for(int j = st; j < st + ans[i]; j++)
		{
			cout << s[i][j];
		}
		cout << "\n";
	}
	return 0;
}