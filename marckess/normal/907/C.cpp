#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	bitset<26> bs;

	for (int i = 0; i < 26; i++)
		bs[i] = 1;

	int n, res = 0;
	char c;
	string s;

	cin >> n;
	while (n--) {
		cin >> c >> s;

		if (c == '!') {
			if (bs.count() == 1)
				res++;

			bitset<26> a;

			for (char c : s)
				a[c-'a'] = 1;

			for (int i = 0; i < 26; i++)
				bs[i] = bs[i] && a[i];
		}

		if (c == '.') {
			for (char c : s)
				bs[c-'a'] = 0;
		}

		if (c == '?') {
			if (bs.count() == 1 && n) {
				res++;
			} else {
				bs[s[0]-'a'] = 0;
			}
		}
	}

	cout << res << endl;

	return 0;
}