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

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n; cin >> n;

	vector<int> price(n);
	vector<set<int>> col(3);

	for (int i = 0; i < n; ++i){
		cin >> price[i];
	}

	for (int j = 0; j < 2; ++j)	
		for (int i = 0; i < n; ++i){
			int c; cin >> c; c--;
			col[c].insert( price[i] );
		}

	int q; cin >> q;

	while (q--){
		int c; cin >> c; c--;
		
		if (col[c].empty()){
			cout << -1 << " ";
			continue;
		}

		int p = *col[c].begin();
		for (int j = 0; j < 3; ++j)
			col[j].erase(p);
		cout << p << " ";
	}

	cout << endl;

	return 0;
}