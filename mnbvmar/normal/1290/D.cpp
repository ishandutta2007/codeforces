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
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

vector<bool> is_avail;
vi seq, mem;
int startmem;
int n, k;
ll nused = 0;

bool Taste(int x) {
	#ifdef LOCAL
	++nused;
	char ans = 'N';
	for (int i = startmem; i < SZ(mem); ++i) {
		if (mem[i] == seq[x]) {
			ans = 'Y';
			break;
		}
	}
	mem.push_back(seq[x]);
	startmem = max(startmem, SZ(mem) - k);
	debug() << "Taste " << x << imie(ans);
	#else
	cout << "? " << x + 1 << endl;
	char ans; cin >> ans;
	#endif
	if (ans == 'Y') { is_avail[x] = false; }
	return ans == 'Y';
}

vector<vi> blocks;

void Clear() {
	#ifdef LOCAL
	debug() << "Clear";
	mem.clear();
	startmem = 0;
	#else
	cout << "R" << endl;
	#endif
}

void Answer() {
	#ifdef LOCAL
	cerr << "Used: " << nused << ", allowed: " << 3 * n * n / (2 * k) << "\n";
	#endif
	const int ans = count(ALL(is_avail), true);
	cout << "! " << ans << endl;
}

void AddBlock(int bid) {
	for (int v : blocks[bid]) {
		if (is_avail[v]) {
			Taste(v);
		}
	}
}

int main() {
	cin >> n >> k;
	#ifdef LOCAL
	seq.resize(n);
	for (int &x : seq) { cin >> x; }
	#endif

	is_avail.resize(n, true);

	if (k == n) {
		for (int i = 0; i < n; ++i) {
			Taste(i);
		}
		Answer();
	} else if (k == 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				Clear();
				Taste(i);
				Taste(j);
			}
		}
		Answer();
	} else {
		const int bsize = k / 2;
		blocks.resize(n / bsize);
		for (int i = 0; i < SZ(blocks); ++i) {
			for (int j = 0; j < bsize; ++j) {
				blocks[i].push_back(i * bsize + j);
			}
		}

		const int nblocks= SZ(blocks);
		debug() << imie(nblocks);

		for (int i = 1; i < nblocks; ++i) {
			AddBlock(0);
			AddBlock(i);
			Clear();
		}

		for (int i = 1; i * 2 < nblocks; ++i) {
			AddBlock(i);
			AddBlock(nblocks - i - 1);
			Clear();
		}

		vector<vi> adjs;
		for (int v = 1; v < nblocks - 1; ++v) {
			vi adj(nblocks, -1);
			adj[nblocks - 1] = v;
			adj[v] = nblocks - 1;
			for (int i = 1; i < nblocks / 2; ++i) {
				int a = (v - i + nblocks-1) % (nblocks-1), b = (v + i) % (nblocks-1);
				adj[a] = b;
				adj[b] = a;
			}
			debug() << imie(adj);
			assert(count(ALL(adj), -1) == 0);
			adjs.push_back(adj);
		}

		for (int i = 0; i < SZ(adjs); i += 2) {
			vi &A = adjs[i], &B = adjs[i + 1];
			vi path{0};
			int prev = -1;

			while (SZ(path) < nblocks) {
				const int v = path.back();
				if (A[v] == prev) {
					path.push_back(B[v]);
				} else {
					path.push_back(A[v]);
				}
				prev = v;
			}

			debug() << imie(path);
			for (int v : path) {
				AddBlock(v);
			}
			Clear();
		}

		Answer();
	}
}