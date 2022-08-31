#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXX = 1200000;

ll n;

ll dp[100000];

ll ad[100000];

vector<ll> ml;
vector<pair<ll, ll> > go;
vector<ll> pr;
int ff[MAXX];


int main() {
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	}

	for (ll i = 2; i < MAXX; ++i) {
		if (ff[i])
			continue;
		pr.push_back(i);
		for (ll j = i * i; j < MAXX; j += i)
			ff[j] = 1;
	}
	

	for (ll i = 1; i * i <= n; ++i) {
		if (n % i != 0)
			continue;
		ml.push_back(i);
		if (i * i != n)
			ml.push_back(n / i);
	}
	sort(ml.begin(), ml.end());

	for (int i = 0; i < (int)ml.size(); ++i) {
		if (ml[i] < 3)
			continue;
		ll lst = 0;
		ll xx = ml[i] - 1;
		for (ll j = 0; pr[j] * pr[j] <= xx; ++j) {
			if (xx % pr[j] != 0)
				continue;
			lst = pr[j];
			while (xx % pr[j] == 0)
				xx /= pr[j];
			break;
		}
		if (lst == 0) {
			go.push_back(make_pair(xx, ml[i]));
		}
		else {
			if (xx == 1) {
				go.push_back(make_pair(lst, ml[i]));
			}
		}
	}

	sort(go.begin(), go.end());
	//for (auto i:ml)
	//	cout << i << " ";
	//cout << "\n";
	//for (auto x:go)
	//	cout << x.first << " " << x.second << "\n";

	dp[0] = 1;

	int lst = 0;

	for (int i = 0; i < (int)go.size(); ++i) {
		if (i == (int)go.size() - 1 || go[i + 1].first != go[i].first) {
			memset(ad, 0, sizeof(ad[0]) * (int)ml.size());
			for (int j = lst; j <= i; ++j) {
				int now = 0;
				for (int j1 = 0; now < (int)ml.size() && j1 < (int)ml.size(); ++j1) {
					while (now < (int)ml.size() && go[j].second * ml[j1] > ml[now])
						++now;
					if (now < (int)ml.size() && go[j].second * ml[j1] == ml[now])
						ad[now] += dp[j1];
				}
			}
			for (int j = 0; j < (int)ml.size(); ++j)
				dp[j] += ad[j];
			lst = i + 1;
		}
	}

	cout << dp[ml.size() - 1];

	return 0;
}