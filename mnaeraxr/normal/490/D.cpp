#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

vector<pii> __solve(int64 a){
	set<int64> S;
	S.insert(a);

	vector<pii> V;
	V.push_back((pii){a, 0});
	int pnt = 0;

	while (pnt < V.size()){
		auto cur = V[pnt++];
		int64 val = cur.first;
		int64 t = cur.second;

		if (val % 2 == 0){
			int64 nxt = val / 2;
			if (!S.count(nxt)){
				S.insert(nxt);
				V.push_back({nxt, t + 1});
			}
		}
		if (val % 3 == 0){
			int64 nxt = 2 * val / 3;
			if (!S.count(nxt)){
				S.insert(nxt);
				V.push_back({nxt, t + 1});
			}
		}
	}
	return V;
}

map<int64,pair<int64,pii>> solve(int64 a, int64 b){
	auto va = __solve(a);
	auto vb = __solve(b);
	map<int64,pair<int64,pii>> ans;

	for (auto v1 : va){
		for (auto v2 : vb){
			int64 cur = v1.first * v2.first;
			int tcur = v1.second + v2.second;
			if (!ans.count(cur) || ans[cur].first > tcur){
				ans[cur] = {tcur, {v1.first, v2.first}};
			}
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;	

	auto m1 = solve(a1, b1);
	auto m2 = solve(a2, b2);

	int64 t = -1;
	pii a, b;

	for (auto v1 : m1){
		if (m2.count(v1.first)){
			auto v2 = m2[v1.first];
			if (t == -1 || v1.second.first + v2.first < t){
				t = v1.second.first + v2.first;
				a = v1.second.second;
				b = v2.second;
			}
		}
	}

	if (t == -1) cout << -1 << endl;
	else{
		cout << t << endl;
		cout << a.first << " " << a.second << endl;
		cout << b.first << " " << b.second << endl;
	}


	return 0;
}