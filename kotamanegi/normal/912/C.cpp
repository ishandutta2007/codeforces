#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 2000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
#define ll long long
vector<pair<ll,ll>> enemy_data[200000];
vector<pair<ll, ll>> alive[200000];
long long imos[2000000] = {};
int main() {
#define int long long
	ll n, m;
	scanf("%lld%lld", &n, &m);
	ll bounty, inc, dmg;
	scanf("%lld%lld%lld", &bounty, &inc, &dmg);
	vector<pair<ll,ll>> enemy_health;
	enemy_health.push_back(make_pair(-1, -1));
	REP(i, n) {
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		enemy_health.push_back(make_pair(a,c));
		enemy_data[i+1].push_back(make_pair(0,b));
	}
	for (int i = 0;i < m;++i) {
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		enemy_data[b].push_back(make_pair(a, c));
	}
	for (int i = 1;i <= n;++i) {
		sort(enemy_data[i].begin(), enemy_data[i].end());
		for (int q = 0;q < enemy_data[i].size();++q) {
			if (enemy_health[i].second != 0&&dmg < enemy_health[i].first) {
				if (dmg >= enemy_data[i][q].second) {
					ll finaling = enemy_data[i][q].first + max((ll)0, (dmg - enemy_data[i][q].second) / enemy_health[i].second);
					if (q != enemy_data[i].size() - 1) {
						finaling = min(finaling, enemy_data[i][q+1].first - 1);
					}
					alive[i].push_back(make_pair(enemy_data[i][q].first, finaling));
				}
			}else{
				if (dmg >= enemy_data[i][q].second) {
					if (q != enemy_data[i].size() - 1) {
						alive[i].push_back(make_pair(enemy_data[i][q].first, enemy_data[i][q+1].first-1));
					}
					else {
						if (inc != 0) {
							cout << -1 << endl;
							return 0;
						}
						else {
							alive[i].push_back(make_pair(enemy_data[i][q].first,(long long)100000000000));
						}
					}
				}
			}
		}
	}
	vector<int> sorter;
	for (int i = 1;i <= n;++i) {
		for (int q = 0;q < alive[i].size();++q) {
			sorter.push_back(alive[i][q].first);
			sorter.push_back(alive[i][q].second);
			sorter.push_back(alive[i][q].second+1);
		}
	}
	map<long long, long long> to_zip;
	map<long long, long long> to_unzip;
	long long now_itr = 1;
	if (sorter.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	sort(sorter.begin(), sorter.end());
	to_zip[sorter[0]] = 0;
	to_unzip[0] = sorter[0];
	for (int i = 1;i < sorter.size();++i) {
		if (sorter[i] != sorter[i - 1]) {
			to_zip[sorter[i]] = now_itr;
			to_unzip[now_itr] = sorter[i];
			now_itr++;
		}
	}
	for (int i = 1;i <= n;++i) {
		for (int q = 0;q < alive[i].size();++q) {
			imos[to_zip[alive[i][q].first]]++;
			imos[to_zip[alive[i][q].second + 1]]--;
		}
	}
	long long ans = -1;
	for (int i = 0;i <= now_itr;++i) {
		ans = max(ans, imos[i] * (bounty + inc*to_unzip[i]));
		imos[i + 1] += imos[i];
	}
	cout << ans << endl;
	return 0;
}