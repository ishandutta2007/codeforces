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
	
	vi z = zfunction(s);
	
	int m = 0, n = (int)s.length();
	
	for (int i = 1; i < n; ++i){		
		if (i + z[i] == n && z[i] <= m){
			cout << s.substr(i) << endl;
			return 0;
		}
		
		m = max(m, z[i]);
	}
	
	cout << "Just a legend" << endl;
	
	return 0;
}