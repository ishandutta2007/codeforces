#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, m, i, j, cur, free = 0, from;
	string p;
	cin >> n >> m >> p;
	vector<ll> s1(n, '?');
	string s(s1.begin(), s1.end());
	vector<ll> seq(m);
	for (i = 0; i < m; i++) {
		cin >> cur;
		cur--;
		seq[i] = cur;
		if (cur >= free) {
			free = cur;
			from = 0;
		}
		else {
			from = free - cur;
		}
		for (; from < p.size(); from++, free++)
			s[free] = p[from];
	}

	vector<ll> pi(p.size(), 0);
	for (i = 1; i < p.size(); i++) {
		j = pi[i - 1];
		while (j  && (p[i] != p[j]))
			j = pi[j - 1];
		if (p[i] == p[j])
			j++;
		pi[i] = j;
	}

	vector<ll> seq2;
	j = 0;
	for (i = 0; i < s.size(); i++) {
		while (j  && ((j >= p.size()) || (s[i] != p[j])))
			j = pi[j - 1];
		if (s[i] == p[j])
			j++;
		if (j == p.size())
			seq2.push_back(i - p.size() + 1);
	}

	ll res = seq.size();
	for (i = 0, j = 0; (i < seq.size()) && (j < seq2.size()); seq[i] < seq2[j] ? i++ : j++)
		if (seq[i] == seq2[j])
			res--;
	if (res)
		cout << 0;
	else {
		res = 1;
		for (i = 0; i < s.size(); i++)
			if (s[i] == '?')
				res = (res * 26) % 1000000007;
		cout << res;
	}

	return 0;
}