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
typedef pair <int, ll> ill;

const int Maxn = 505;

int n;
int a[Maxn];
vector <ill> seq, my;

int Div(int a, int b) { return a / b + int(a % b > 0); }

void Add(vector <ill> &seq, ill val)
{
	if (seq.empty() || seq.back().first != val.first) {
		seq.push_back(val);
	} else {
		seq.back().second = min(seq.back().second, val.second);
	}
}

void Get(int a, vector <ill> &seq)
{
	int cur = 1;
	while (cur <= a) {
		int tims = Div(a, cur);
		if (cur * tims == a) Add(seq, ill(tims + 1, cur));
		Add(seq, ill(tims, cur));
		if (tims - 1 <= 0) break;
		cur = Div(a, tims - 1);
	}
}

void Merge()
{
	vector <ill> res;
	int i = 0, j = 0;
	while (i < seq.size() && j < my.size())
		if (seq[i].first > my[j].first) i++;
		else if (seq[i].first < my[j].first) j++;
		else { res.push_back(ill(seq[i].first, seq[i].second + my[j].second)); i++; j++; }
	seq = res;
}

int main()
{
	scanf("%d", &n);
	scanf("%d", &a[0]); Get(a[0], seq);
	for (int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
		my.clear(); Get(a[i], my);
		Merge();
	}
	ll best = seq[0].second;
	for (int i = 1; i < seq.size(); i++)
		if (seq[i].second < best) best = seq[i].second;
	printf("%I64d\n", best);
	return 0;
}