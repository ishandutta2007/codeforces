#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

bool ok(set<pii> t, int s, int d){
	auto it = t.lower_bound({s, -1});

	if (it != t.end() && it->first < s + d)
		return false;

	if (it != t.begin()){
		it--;
		if (it->second >= s)
			return false;
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	set<int> s = {1};
	set<pii> t;

	for (int i = 0; i < n; ++i){
		int a, b; cin >> a >> b;

		if (ok(t, a, b)){
			cout << a << " " << a + b - 1 << endl;
			t.insert({a, a + b - 1});
			s.insert(a + b);
		}
		else{
			for (auto v : s){
				if (ok(t, v, b)){
					cout << v << " " << v + b - 1 << endl;
					t.insert({v, v + b - 1});
					s.insert(v + b);
					break;
				}
			}
		}
	}


	return 0;
}