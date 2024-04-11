#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;
const ll Inf = 10000000000ll;

int n;
int a[Maxn];
string s;
char res[Maxn];

void Write(int ind, char ch)
{
	if (ind < 0 || ind >= n - 1) return;
	res[ind] = ch;
}

void cWrite(int ind, char ch)
{
	if (ind < 0 || ind >= n - 1 || res[ind] != '?') return;
	res[ind] = ch;
}

int best, bwth;

void Gen(int lvl, int sum, int mult, int wth, const vector <ll> &seq)
{
	int ind = 2 * lvl + 1;
	if (ind >= seq.size()) {
		if (sum + mult > best) {
			best = sum + mult;
			bwth = wth;
		}
	} else {
		Gen(lvl + 1, sum + mult + seq[ind], seq[ind + 1], (wth | 1 << lvl), seq);
		Gen(lvl + 1, sum, mult * seq[ind + 1], wth, seq);
	}
}

void Solve(int l, int r)
{
	while (l <= r && a[l] == 1) {
		Write(l - 1, '+');
		Write(l, '+');
		l++;
	}
	while (l <= r && a[r] == 1) {
		Write(r - 1, '+');
		Write(r, '+');
		r--;
	}
	if (l > r) return;
	ll res1 = 1;
	for (int i = l; i <= r; i++)
		res1 = min(Inf, res1 * a[i]);
	if (res1 > 2 * (r - l + 1)) {
		for (int i = l - 1; i <= r; i++)
			cWrite(i, '*');
		return;
	}
	vector <ll> seq;
	vector <ii> ab;
	int cur = 1;
	for (int i = l; i <= r; i++)
		if (a[i] == 1) {
			if (cur > 1) {
				seq.push_back(0);
				ab.push_back(ii(i, -1));
				cur = 1;
			}
			seq.back()++;
			ab.back().second = i;
		} else {
			if (cur == 1) {
				seq.push_back(1);
				ab.push_back(ii(i, -1));
			}
			cur *= a[i];
			seq.back() *= a[i];
			ab.back().second = i;
		}
	best = 0;
	Gen(0, 0, seq[0], 0, seq);
	int siz = (seq.size() + 1) / 2;
	for (int i = 0; i < siz; i++) {
		int ind = 2 * i + 1;
		if (bwth & 1 << i)
			for (int j = ab[ind].first - 1; j <= ab[ind].second; j++)
				Write(j, '+');
	}
	for (int i = l - 1; i <= r; i++)
		cWrite(i, '*');
}

int main()
{
	scanf("%d", &n);
	fill(res, res + n, '?');
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	cin >> s;
	if (s.find('+') != string::npos && s.find('*') != string::npos) {
		int lst = -1;
		for (int i = 0; i < n; i++)
			if (a[i] == 0) {
				Write(i - 1, '+');
				Write(i, '+');
				if (lst != -1) Solve(lst, i - 1);
				lst = -1; 
			} else if (lst == -1) lst = i;
		if (lst != -1)
			Solve(lst, n - 1);
	} else if (s.find('+') != string::npos)
		for (int i = 0; i < n; i++)
			Write(i, '+');
	else {
		if (s.find('-') != string::npos)
			for (int i = 0; i < n; i++) if (a[i] == 0)
				Write(i - 1, '-');
		for (int i = 0; i < n; i++)
			if (s.find('*') != string::npos)
				cWrite(i, '*');
			else cWrite(i, '-');
	}
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		if (i < n - 1)
			printf("%c", res[i]);
	}
	printf("\n");
    return 0;
}