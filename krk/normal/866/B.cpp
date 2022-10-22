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

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int N, S;
int s[Maxn], a[Maxn], b[Maxn];
vector <ii> eatA, eatB;
int modA = 0, modB = 0;
ll cur;
ll res;

ll Lose(const vector <ii> &seq, int tk)
{
	ll val = 0;
	for (int i = 0; i < seq.size() && tk > 0; i++) {
		int got = min(tk, seq[i].second);
		val += ll(got) * seq[i].first; tk -= got;
	}
	return val;
}

int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &s[i], &a[i], &b[i]);
		if (a[i] >= b[i]) { modA = (modA + s[i]) % S; eatA.push_back(ii(a[i] - b[i], s[i])); cur += ll(s[i]) * a[i]; }
		else { modB = (modB + s[i]) % S; eatB.push_back(ii(b[i] - a[i], s[i])); cur += ll(s[i]) * b[i]; }
	}
	if (modA + modB > S) res = cur;
	else {
		sort(eatA.begin(), eatA.end());
		sort(eatB.begin(), eatB.end());
		res = cur - min(Lose(eatA, modA), Lose(eatB, modB));
	}
	cout << res << endl;
	return 0;
}