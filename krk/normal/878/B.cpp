#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 100005;

int n, k, m;
ll res;
int a[Maxn];
vector <lli> my;

ll Add(vector <lli> &seq, lli p)
{
	//printf("Add(%lld, %d)\n", p.first, p.second);
	ll res = 0;
	res += p.first / k * k; p.first %= k;
	if (p.first == 0) return res;
	if (seq.empty() || seq.back().second != p.second) seq.push_back(p);
	else {
		seq.back().first += p.first;
		res += seq.back().first / k * k; seq.back().first %= k;
		if (seq.back().first == 0) seq.pop_back();
	}
	return res;
}

ll Get(vector <lli> &A, vector <lli> B)
{
	vector <lli> tmp = A;
	ll res = 0;
	int tk = min(Maxn, int(B.size()));
	for (int i = 0; i < tk; i++)
		res += Add(tmp, B[i]);
	for (int i = tk; i < B.size(); i++)
		tmp.push_back(B[i]);
	if (tmp.size() < 2 * Maxn) A = tmp;
	else {
		A.clear();
		for (int i = 0; i < Maxn; i++)
			A.push_back(tmp[i]);
		for (int i = Maxn; i > 0; i--)
			A.push_back(tmp[int(tmp.size()) - i]);
	}
	return res;
}

int main()
{
	scanf("%d %d %d", &n, &k, &m);
	int tk = m / 2;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	ll cur = 0;
	for (int i = 0, j; i < n; i = j) {
		j = i;
		while (j < n && a[i] == a[j]) j++;
		cur += Add(my, lli(j - i, a[i]));
	}
	vector <lli> R;
	int savm = m;
	while (m) {
		if (m & 1) res += cur + Get(R, my);
		m >>= 1;
		cur = 2 * cur + Get(my, my);
	}
	cout << ll(n) * savm - res << endl;
	return 0;
}