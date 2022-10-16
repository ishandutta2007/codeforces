//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
	enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
	ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

struct Point {
	int x, y;
	int Dist(const Point &p) const {
		return abs(x - p.x) + abs(y - p.y);
	}
};

const int kMaxN = 14;
const int kMaxM = 110;
const int kInf = 1.5e9;

int n, m;
Point fast_trav[kMaxN];
Point quest_loc[kMaxM];
int quest_tm[kMaxM];

int min_limbo_time[1 << kMaxN][kMaxM];
int max_quest_loc[1 << kMaxN][kMaxM];
bool vis_limbo[1 << kMaxN][kMaxM];
bool vis_quest[1 << kMaxN][kMaxM];
int min_dist_needed[1 << kMaxN][kMaxM];
int min_dist_needed_limbo[1 << kMaxN][kMaxN];

struct LimboEvent {
	int tm;
	int mask;
	int num_ok;

	bool operator>(const LimboEvent &ev) const {
		return tm > ev.tm;
	}
};

priority_queue<LimboEvent, vector<LimboEvent>, greater<LimboEvent>> que;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> fast_trav[i].x >> fast_trav[i].y;
	}
	for (int i = 0; i < m; ++i) {
		cin >> quest_loc[i].x >> quest_loc[i].y >> quest_tm[i];
	}

	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j <= m; ++j) {
			min_limbo_time[i][j] = kInf;
			max_quest_loc[i][j] = (j == 0 ? 0 : -kInf);

			min_dist_needed[i][j] = kInf;
			for (int k = 0; k < n; ++k) {
				if ((i >> k) & 1) {
					min_dist_needed[i][j] = min(min_dist_needed[i][j],
						fast_trav[k].Dist(quest_loc[j]));
				}
			}
		}

		for (int j = 0; j <= n; ++j) {
			min_dist_needed_limbo[i][j] = kInf;
			for (int k = 0; k < n; ++k) {
				if ((i >> k) & 1) {
					min_dist_needed_limbo[i][j] = min(min_dist_needed_limbo[i][j],
						fast_trav[k].Dist(fast_trav[j]));
				}
			}
		}
	}

	auto AddLimbo = [&](int mask, int num_done, int tm) {
		if (!mask) { return; }
		if (tm < min_limbo_time[mask][num_done]) {
			min_limbo_time[mask][num_done] = tm;
			que.push(LimboEvent{tm, mask, num_done});
		}
	};

	for (int i = 0; i < n; ++i) {
		AddLimbo(1 << i, 0, 0);
	}
	for (int msk = 0; msk < (1 << n); ++msk) {
		for (int i = 0; i < m; ++i) {
			max_quest_loc[msk][i] = -kInf;
		}
	}
	for (int i = 0; i < m; ++i) {
		max_quest_loc[0][i] = 1;
	}

	int ans = -1;

	vector<int> quest_order(m);
	iota(ALL(quest_order), 0);
	sort(ALL(quest_order), [&](int lhs, int rhs) {
		return quest_tm[lhs] < quest_tm[rhs];
	});
	int quest_ptr = 0;
	int next_quest_tm = quest_tm[quest_order[0]];

	while (!que.empty() || quest_ptr < m) {
		int next_queue_tm = kInf;
		if (!que.empty()) {
			next_queue_tm = que.top().tm;
		}

		if (next_quest_tm <= next_queue_tm) {
			const int who = quest_order[quest_ptr];
			debug() << imie(who) << imie(next_quest_tm);
			for (int nxt = 0; nxt < m; ++nxt) {
				if (who == nxt || quest_tm[nxt] < next_quest_tm + quest_loc[who].Dist(quest_loc[nxt])) {
					continue;
				}
				for (int mask = 0; mask < (1 << n); ++mask) {
					int &elem = max_quest_loc[mask][nxt];
					elem = max(elem, max_quest_loc[mask][who] + 1);
				}
			}

			for (int mask = 0; mask < (1 << n); ++mask) {
				if (max_quest_loc[mask][who] < 0) { continue; }
				debug() << imie(who) << imie(mask) << imie(max_quest_loc[mask][who]);
				ans = max(ans, max_quest_loc[mask][who]);
				AddLimbo(mask, max_quest_loc[mask][who], next_quest_tm);

				for (int nxt = 0; nxt < n; ++nxt) {
					if ((mask >> nxt) & 1) { continue; }
					AddLimbo(mask | (1 << nxt), max_quest_loc[mask][who],
						next_quest_tm + quest_loc[who].Dist(fast_trav[nxt]));
				}
			}

			++quest_ptr;
			next_quest_tm = (quest_ptr == m ? kInf : quest_tm[quest_order[quest_ptr]]);
		} else {
			auto item = que.top();
			que.pop();
			const int mask = item.mask;
			const int num_ok = item.num_ok;
			ans = max(ans, num_ok);
			debug() << imie(mask) << imie(num_ok) << imie(next_queue_tm);
			if (vis_limbo[mask][num_ok]) { continue; }
			vis_limbo[mask][num_ok] = true;
			for (int nxt = 0; nxt < m; ++nxt) {
				if (quest_tm[nxt] < next_queue_tm + min_dist_needed[mask][nxt]) {
					continue;
				}
				int &elem = max_quest_loc[mask][nxt];
				elem = max(elem, num_ok + 1);
			}

			for (int nxt = 0; nxt < n; ++nxt) {
				if ((mask >> nxt) & 1) { continue; }
				const int next_tm = next_queue_tm + min_dist_needed_limbo[mask][nxt];
				AddLimbo(mask | (1 << nxt), num_ok, next_tm);
			}
		}
	}

	cout << ans << "\n";
}