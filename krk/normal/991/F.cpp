#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxd = 11;
const int Maxm = 1000000;

int sum[Maxm];
ll n;
map <ll, ii> M[Maxd];
map <ll, int> inpower;
string best;

string toString(ll x)
{
	stringstream ss; ss << x;
	string s; ss >> s;
	return s;
}

string toPower(const ii &p)
{
	return toString(p.first) + "^" + toString(p.second);
}

int Sum(ll x)
{
	int res = 0;
	while (x) {
		res++;
		x /= 10;
	}
	return res;
}

int main()
{
	for (int i = 1; i < Maxm; i++)
		sum[i] = Sum(i);
	cin >> n; best = toString(n);
	for (int i = 2; i <= n / i; i++) {
		ll cur = i;
		int cnt = 1;
		while (cur <= n / i) {
			cur *= i; cnt++;
			int need = sum[i] + 1 + sum[cnt];
			if (need < Maxd) {
				M[need][cur] = ii(i, cnt);
				map <ll, int>::iterator it = inpower.find(cur);
				if (it == inpower.end())
					inpower[cur] = need;
				else it->second = min(it->second, need);
			}
		}
	}
	for (int i = 1; i < Maxd && i < best.length(); i++)
		for (auto& p: M[i]) {
			if (p.first == n && i < best.length())
				best = toPower(p.second);
			// 7
			ll mult = n / p.first;
			ll add = n - p.first * mult;
			int cand = i;
			if (mult != 1) cand += 1 + Sum(mult);
			if (add > 0) cand += 1 + Sum(add);
			if (cand < best.length()) {
				best = toPower(p.second);
				if (mult != 1) best += "*" + toString(mult);
				if (add > 0) best += "+" + toString(add);
			}
			// 1
			cand = i + 1 + Sum(n - p.first);
			if (cand < best.length())
				best = toPower(p.second) + "+" + toString(n - p.first);
			// 2
			if (n % p.first == 0) {
				int cand = i + 1 + Sum(n / p.first);
				if (cand < best.length())
					best = toPower(p.second) + "*" + toString(n / p.first);
			}
			// 3, 5
			for (int j = 2; j < 100 && p.first * j <= n; j++) {
				int cand = i + 1 + sum[j];
				if (cand >= best.length()) break;
				ll got = n - p.first * j;
				map <ll, int>::iterator it = inpower.find(got);
				if (it != inpower.end()) {
					cand += 1 + it->second;
					if (cand < best.length())
						best = toPower(M[it->second][it->first]) + "+" + toPower(p.second) + "*" + toString(j);
				}
				cand = i + 1 + sum[j];
				if (n % (p.first * j) == 0) {
					got = n / (p.first * j);
					map <ll, int>::iterator it = inpower.find(got);
					if (it != inpower.end()) {
						cand += 1 + it->second;
						if (cand < best.length())
							best = toPower(M[it->second][it->first]) + "*" + toPower(p.second) + "*" + toString(j);
					}
				} 
			}
			for (int j = 1; j < Maxd && i + 1 + j < best.length(); j++) {
				// 4
				map <ll, ii>::iterator it = M[j].upper_bound(n / p.first);
				if (it != M[j].begin()) {
					it--;
					int cand = i + 1 + j;
					ll lft = n - p.first * it->first;
					if (lft > 0) cand += 1 + Sum(lft);
					if (cand < best.length()) {
						best = toPower(p.second) + "*" + toPower(it->second);
						if (lft > 0) best += "+" + toString(lft);
					}
				}
				// 6
				it = M[j].upper_bound(n - p.first);
				if (it != M[j].begin()) {
					it--;
					int cand = i + 1 + j;
					ll lft = n - p.first - it->first;
					if (lft > 0) cand += 1 + Sum(lft);
					if (cand < best.length()) {
						best = toPower(p.second) + "+" + toPower(it->second);
						if (lft > 0) best += "+" + toString(lft);
					}
				}
			}
		}
	cout << best << endl;
	return 0;
}