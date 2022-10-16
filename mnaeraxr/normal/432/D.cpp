#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

vector<int> zfunction(const string &s)
{
	int n = s.length();
	vector<int> z(n, n);

	for (int i = 1, g = 0, f; i < n; ++i)
		if (i < g && z[i - f] != g - i)
			z[i] = min(z[i - f], g - i);
		else
		{
			for (g = max(g, i), f = i; g < n && s[g] == s[g - f]; ++g);
			z[i] = g - f;
		}

	return z;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	int n = (int)s.length();
	
	vi z = zfunction(s);
	z[0] = n;
	
	vi acc(n + 1);
	for (int i = 0; i < n; ++i)
		acc[z[i]]++;
	
	for (int i = n - 1; i >= 0; --i)
		acc[i] += acc[i + 1];
	
	vector<pii> ans;
	
	for (int i = n - 1; i >= 0; --i){
		if (i + z[i] == n)
			ans.push_back(pii(z[i], acc[z[i]]));
	}
	
	cout << ans.size() << endl;
	
	for (auto a : ans)
		cout << a.first << " " << a.second << endl;
	
	return 0;
}