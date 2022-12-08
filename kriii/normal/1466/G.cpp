#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const long long mod = 1000000007, inv2 = (mod + 1) / 2;

int n, q; char c[1001001];
string s[23], r[23], t;
long long pw[100100] = { 1, }, pr[26][100100];

void input(string &s)
{
	scanf ("%s", c);
	s = c;
}

int fail[1001001], last;
bool chk1[1001001], chk2[1001001];
int count(string &s, string &t)
{
	int k = -1;
	fail[0] = k;
	for (int i = 1; i < t.length(); i++){
		while (k >= 0 && t[k + 1] != t[i]) k = fail[k];
		if (t[k + 1] == t[i]) k++;
		fail[i] = k;
	}

	int res = 0;
	k = -1;
	for (int i = 0; i < s.length(); i++){
		while (k >= 0 && t[k + 1] != s[i]) k = fail[k];
		if (t[k + 1] == s[i]) k++;
		if (i + 1 == s.length()) last = k;
		if (k + 1 == t.length()) k = fail[k], res++;
	}
	return res;
}

int main()
{
	scanf ("%d %d", &n, &q);
	input(s[0]); input(t);
	for (int i = 0; i < n; i++){
		s[i + 1] = s[i] + t[i] + s[i];
		if (s[i + 1].length() > 1000000) break;
	}
	for (int i = 0; i < n; i++){
		if (s[i].empty()) break;
		r[i] = s[i];
		reverse(r[i].begin(), r[i].end());
	}

	long long v = 1;
	for (int i = 1; i <= n; i++){
		v = v * inv2 % mod;
		pw[i] = pw[i - 1] * 2 % mod;
		pr[t[i - 1] - 'a'][i] = v;
		for (int k = 0; k < 26; k++) pr[k][i] = (pr[k][i] + pr[k][i - 1]) % mod;
	}

	while (q--){
		int u = 0, v; scanf ("%d", &v);
		string w; input(w);

		while (u < v && s[u].length() <= w.length()) u++;
		for (int i = 0; i <= w.length(); i++) chk1[i] = chk2[i] = 0;

		long long res = count(s[u], w) * pw[v - u] % mod;
		while (last >= 0){
			chk1[last + 1] = 1;
			last = fail[last];
		}
		chk1[0] = 1;
		reverse(w.begin(), w.end());
		count(r[u], w);
		if (last + 1 == w.length()) last = fail[last];
		while (last >= 0){
			chk2[w.length()-2-last] = 1;
			last = fail[last];
		}
		chk2[w.length() - 1] = 1;
		reverse(w.begin(), w.end());

		for (int i = 0; i < w.length(); i++){
			if (chk1[i] && chk2[i]){
				long long *a = pr[w[i] - 'a'];
				res = (res + (a[v] + mod - a[u]) * pw[v]) % mod;
			}
		}

		printf ("%lld\n", res);
	}

	return 0;
}