#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

bool compare(pii a, pii b){
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int getMin(set<pii> &S, int b){
	auto it = S.upper_bound({b, oo});

	if (it != S.begin()){
		it--;
		if (it->second >= b) return b;
		it++;
	}

	return it != S.end() ? it->first : oo;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	int step = 0;
	set<pii> S = { {1, 1} };

	vector<pii> V(m);
	for (int i = 0; i < m; ++i){
		cin >> V[i].first >> V[i].second;
	}

	sort(V.begin(), V.end(), compare);

	for (int i = 0, j; i < m; i = j){
		set<pii> N;
		if (V[i].second > step + 1){
			int b = S.begin()->first;
			for (j = i; j < m && V[i].second == V[j].second; ++j){
				if (b <= V[j].first - 1)
					N.insert({b, V[j].first - 1});
				b = max(V[j].first + 1, b);
			}
			if (b <= n) N.insert({b, n});
		}
		else{
			int b = 1;

			for (j = i; j < m && V[i].second == V[j].second; ++j){
				if (b < V[j].first){
					int p = getMin(S, b);
					if (p < V[j].first){
						N.insert({p, V[j].first - 1});
					}
				}
				b = V[j].first + 1;
			}

			if (b <= n){
				int p = getMin(S, b);
				if (p <= n)
					N.insert({p, n});
			}
		}

		S = N;

		if (S.empty()) break;
		step = V[i].second;

//		cout << step << endl;
//		for (auto s : S)
//			cout << s.first << " " << s.second << endl;
//		cout << endl;
	}

	if (step < n && !S.empty())
		S.insert({n, n});

	if (!S.empty() && S.rbegin()->second == n)
		cout << 2 * n - 2 << endl;
	else
		cout << -1 << endl;

	return 0;
}
/*
999999996 6
1 2
999999996 999999992
999999996 999999995
3 3
999999996 999999993
2 3
 */