#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef long long lint, ll;
typedef long double ld, ldouble;

#define For(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()

#ifdef LOCAL
#pragma comment(linker, "/STACK:16777216")
#endif

void solve(int n, vector<lint> ar, string s)
{
	vector<lint> need_for_lava(n + 1);
	vector<lint> use_for_lava(n + 1);
	for (int i = n - 1; i >= 0; --i)
	{
		need_for_lava[i] = need_for_lava[i + 1];
		if (s[i] == 'L')
			need_for_lava[i] += ar[i];
		else if (s[i] == 'W')
		{
			lint for_lava = min(ar[i], need_for_lava[i]);
			need_for_lava[i] -= for_lava;
			use_for_lava[i] += for_lava;
		}
	}
	fill(all(need_for_lava), 0);
	lint ener = 0;
	For(i, n)
	{
		if (s[i] == 'L')
		{	
			lint energy_used = min(ar[i], ener);
			need_for_lava[i] += ar[i] - energy_used;
			ener -= energy_used;
		}
		else
			ener += use_for_lava[i];
	}
	for (int i = n - 1; i >= 0; --i)
	{
		need_for_lava[i] = max(need_for_lava[i], 0ll) + need_for_lava[i + 1];
		if (s[i] == 'G')
		{
			lint for_lava = min(ar[i], need_for_lava[i]);
			need_for_lava[i] -= for_lava;
			use_for_lava[i] += for_lava;
		}
	}
	vector<lint> need_for_grass(n + 1);
	vector<lint> use_for_grass(n + 1);
	for (int i = n - 1; i >= 0; --i)
	{
		need_for_grass[i] = need_for_grass[i + 1];
		if (s[i] == 'G')
			need_for_grass[i] += ar[i] - use_for_lava[i];
		else if (s[i] == 'W')
		{
			lint for_grass = min(ar[i] - use_for_lava[i], need_for_grass[i]);
			need_for_grass[i] -= for_grass;
			use_for_grass[i] += for_grass;
		}
	}
	

	lint res = 0, energy_for_grass = 0, energy_for_lava = 0;
	bool swam = false;
	For(i, n)
	{
		if (s[i] == 'G')
		{
			energy_for_lava += use_for_lava[i];
			res += use_for_lava[i] * 5;
			lint energy_used = min(energy_for_grass, ar[i] - use_for_lava[i]);
			res += energy_used;
			energy_for_grass -= energy_used;
			res += (ar[i] - use_for_lava[i] - energy_used) * 3;
		}
		else if (s[i] == 'W')
		{
			energy_for_lava += use_for_lava[i];
			res += use_for_lava[i] * 3;
			energy_for_grass += use_for_grass[i];
			res += use_for_grass[i] * 3;
			res += (ar[i] - use_for_lava[i] - use_for_grass[i]) * 2;
			swam = true;
		}
		else if (s[i] == 'L')
		{
			lint energy_used = min(energy_for_lava, ar[i]);
			res += energy_used;
			energy_for_lava -= energy_used;
			res += (ar[i] - energy_used) * (swam ? 4 : 6);
		}
		else
			throw;
	}
	cout << res << '\n';
}

void solve_old(int n, vector<lint> ar, string s)
{
	lint grass_pool = 0, water_pool = 0, res = 0;
	bool swam = false;
	For(i, n)
	{
		if (s[i] == 'G')
		{
			res += ar[i] * 3;
			grass_pool += ar[i];
		}
		else if (s[i] == 'W')
		{
			res += ar[i] * 2;
			water_pool += ar[i];
			swam = true;
		}
		else if (s[i] == 'L')
		{
			res += ar[i];
			lint cur = ar[i];

			lint from_water = min(water_pool, cur);
			water_pool -= from_water;
			cur -= from_water;
			res += from_water;

			lint from_grass = min(grass_pool, cur);
			grass_pool -= from_grass;
			cur -= from_grass;
			res += 2 * from_grass;

			from_water = swam * cur;
			cur -= from_water;
			res += 3 * from_water;

			from_grass = cur;
			cur -= from_grass;
			res += 5 * from_grass;
		}
	}
	cout << res << '\n';
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int n;
	cin >> n;
	vector<lint> ar(n);
	For(i, n)
		cin >> ar[i];
	string s;
	cin >> s;
	solve(n, ar, s);
#ifdef LOCAL
	solve_old(n, ar, s);
	printf("\n\n%.3lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
}