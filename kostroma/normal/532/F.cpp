#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {
}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

#define int li

int mods[] = { 1000000007, 1000000009 };

int pr[] = {31, 2011};

const int C = 200500;
int powers[2][C];

vector<int> hashes[2];

int getHash(int l, int r) {
	int res[2];
	for (int w = 0; w < 2; ++w) {
		res[w] = hashes[w][r] - hashes[w][l] * powers[w][r - l];
		res[w] %= mods[w];
		if (res[w] < 0) {
			res[w] += mods[w];
		}
	}
	return (res[0] << 32) | res[1];
}

void solve() {
	string s, t;
	cin >> t >> s;
	cin >> t >> s;
	for (int w = 0; w < 2; ++w) {
		powers[w][0] = 1;
		for (int i = 1; i < C; ++i) {
			powers[w][i] = (powers[w][i - 1] * pr[w]) % mods[w];
		}

		hashes[w].push_back(0);
		for (int i = 0; i < t.length(); ++i) {
			hashes[w].push_back((hashes[w].back() * pr[w] + t[i]) % mods[w]);
		}
	}

	vector<vector<int>> sums(26);
	for (int j = 0; j < 26; ++j) {
		vector<int> have(2);
		for (int w = 0; w < 2; ++w) {
			have[w] = 0;
			for (int i = 0; i < s.length(); ++i) {
				have[w] = have[w] * pr[w] % mods[w];
				if (s[i] - j == 'a') {
					++have[w];
				}
			}
			have[w] %= mods[w];
		}
		sums[j] = have;
	}

	vector<int> firstOccurrences(26, -1);
	for (int i = 0; i < s.length(); ++i) {
		int cur = s[i] - 'a';
		if (firstOccurrences[cur] == -1) {
			firstOccurrences[cur] = i;
		}
	}
	vector<pair<int, int>> letters(26);
	for (int i = 0; i < 26; ++i) {
		letters[i] = mp(firstOccurrences[i], i);
	}
	sort(all(letters));

	vector<vector<int>> positions(26);
	
	for (int i = 0; i < t.length(); ++i) {
		positions[t[i] - 'a'].push_back(i);
	}

	firstOccurrences.assign(26, -1);
	for (int i = 0; i < s.length(); ++i) {
		int cur = t[i] - 'a';
		if (firstOccurrences[cur] == -1) {
			firstOccurrences[cur] = i;
		}
	}

	vector<int> ans;

	vector<int> perm(26);
	vector<pair<int, int>> curLetters(26);
	vector<char> used(26);
	for (int i = s.length(); i <= t.length(); ++i) {

		for (int r = 0; r < 26; ++r) {
			curLetters[r] = mp(firstOccurrences[r], r);
		}
		sort(all(curLetters));

		used.assign(26, false);
		for (int r = 0; r < 26; ++r) {
			if (letters[r].first == -1) {
				perm[letters[r].second] = -1;
			}
			else {
				perm[letters[r].second] = curLetters[r].second;
				used[curLetters[r].second] = true;
			}
		}

		bool flag = true;
		for (int r = 0; r < 26; ++r) {
			if (perm[r] != -1 && perm[perm[r]] != -1 && perm[perm[r]] != r) {
				flag = false;
				break;
			}
		}
		

		if (flag) {
			vector<int> curHash(2);
			for (int w = 0; w < 2; ++w) {
				for (int i = 0; i < 26; ++i) {
					if (perm[i] != -1) {
						curHash[w] += ('a' + perm[i]) * sums[i][w];
						curHash[w] %= mods[w];
					}
				}
			}

			int checkHash = (curHash[0] << 32) | curHash[1];

			if (checkHash == getHash(i - s.length(), i)) {
				ans.push_back(i - s.length());
			}
		}

		if (i == t.length()) {
			break;
		}

		int leftChar = t[i - s.length()] - 'a';
		auto& curVec = positions[leftChar];
		firstOccurrences[leftChar] = -1;
		int id = upper_bound(all(curVec), i - s.length()) - curVec.begin();
		if (id < curVec.size() && curVec[id] <= i) {
			firstOccurrences[leftChar] = curVec[id];
		}

		int gotChar = t[i] - 'a';
		if (firstOccurrences[gotChar] == -1) {
			firstOccurrences[gotChar] = i;
		}


	}

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] + 1 << ' ';
	}

}