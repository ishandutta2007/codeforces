#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;

const int Maxn = 15;

string s;
int n;
string p[Maxn];
int l[Maxn], r[Maxn];
set <string> was;

bool Equal(const string &x, const string &p, int z)
{
	for (int i = 0; i < x.size(); i++)
		if (x[i] != p[z + i]) return false;
	return true;
}

int main()
{
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i] >> l[i] >> r[i];
	for (int j = 1; j <= s.length(); j++)
		for (int i = 0; i + j <= s.length(); i++) {
			string x = s.substr(i, j);
			if (was.count(x)) continue;
			int k;
			for (k = 0; k < n; k++) {
				int cnt = 0;
				for (int z = 0; z + x.length() <= p[k].length() && 
					 (cnt < l[k] && cnt + p[k].length() - x.length() - z + 1 >= l[k] || cnt <= r[k] && cnt + p[k].length() - x.length() - z + 1 > r[k]); z++)
					cnt += Equal(x, p[k], z);
				if (cnt < l[k] || cnt > r[k]) break;
			}
			if (k == n) was.insert(x);
		}
	printf("%d\n", was.size());
	return 0;
}