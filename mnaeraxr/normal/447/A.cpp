#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int p, n;
	cin >> p >> n;

	set<int> s;

	for (int i = 1; i <= n; ++i){
		int v; cin >> v;

		v %= p;

		if (s.count(v)){
			cout << i << endl;
			return 0;
		}

		s.insert(v);
	}

	cout << -1 << endl;

	return 0;
}