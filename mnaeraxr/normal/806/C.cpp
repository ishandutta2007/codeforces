#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n; cin >> n;


	vector<int64> v(n);
	map<int64,int64> freq;
	for (int i = 0; i < n; ++i){
		cin >> v[i];
		if ((v[i] & (v[i] - 1)) == 0)
			freq[ v[i] ]++;
	}

	int64 a = 1LL << 40;

	multiset<int64> open;
	multiset<pair<int64,int64>> closed;
	int total = 0;

	// for (auto f : freq)
	// 	cout << f.first << " " << f.second << endl;

	while (a){
		while (freq[a]){
			// cout << "here" << a << endl;
			int64 b = a;
			bool ok = true;

			while (b && ok){
				if (!freq[b])
					ok = false;
				b >>= 1;
			}

			if (ok){
				// cout << "ok" << endl;
				open.insert(a);

				b = a;
				while (b){
					freq[b]--;
					b >>= 1;
				}
			}
			else{
				if (open.empty()){
					cout << -1 << endl;
					return 0;
				}

				freq[a]--;
				auto it = open.lower_bound(a);
				closed.insert( {__lg(*it) + 1, a} );
				open.erase( it );
			}
		}

		a >>= 1;
	}

	auto remove = [&](int64 x){
		int64 c = 1LL << __lg(x);
		auto it = open.lower_bound(c);
		if (it == open.end()) return false;
		closed.insert({__lg(*it) + 1, c});
		open.erase(it);
		return true;
	};	

	for (int i = 0; i < n; ++i){
		if (v[i] & (v[i] - 1))
			if (!remove(v[i])){
				cout << -1 << endl;
				return 0;
			}
	}

	int M = open.size() + closed.size();
	int m = M;

	while (true){
		int szc = closed.empty() ? oo : closed.begin()->first + 1;
		int szo = open.empty() ? oo : __lg(*open.begin()) + 1;

		if (szc <= szo){
			auto cur = *closed.begin();
			closed.erase( closed.begin() );

			if (!remove(cur.second)) break;
			bool ok = true;
			for (int64 a = 1LL << (cur.first - 1); a && ok; a >>= 1)
				if (!remove(a)) ok = false;
			if (!ok) break;
		}
		else{
			int64 a = *open.begin();
			open.erase( open.begin() );

			bool ok = true;
			for (; a && ok; a>>=1){
				if (!remove(a)) ok = false;
			}
			if (!ok) break;
		}
		m--;
	}

	for (int i = m; i <= M; ++i)
		cout << i << " \n"[i == M];

	return 0;
}