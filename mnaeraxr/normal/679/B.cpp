#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int64 p3(int64 v){
	return v * v * v;
}

int64 r3(int64 n){
	int64 v = powl(n, 1.0 / 3);
	while (p3(v + 1) <= n) ++v;
	assert(p3(v) <= n && n < p3(v + 1));
	return v;
}

pair<int64,int64> solve(int64 m){
	if (m <= 7){
		return {m, m};
	}

	int64 a = r3(m);

	auto s1 = solve(m - p3(a)); s1.second += p3(a);
	auto s2 = solve(p3(a) - 1 - p3(a - 1)); s2.second += p3(a - 1);

	if (s2.first > s1.first) swap(s1, s2);
	s1.first++;
	return s1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 m; cin >> m;
	auto c = solve(m);
	cout << c.first << " " << c.second << endl;

	return 0;
}