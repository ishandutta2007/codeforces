#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int64,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000;
int printed = 0;

void print(int64 v){
	cout << v << " ";
	printed++;

	if (printed == maxn){
		cout << endl;
		exit(0);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 x, k;
	cin >> x >> k;

	vector<int64> V;

	for (int64 i = 1; i * i <= x; ++i){
		if (x % i == 0){
			V.push_back(i);
			if (i * i != x)
				V.push_back(x / i);
		}
	}

	sort(V.begin(), V.end());

	vector<vi> adj(V.size());

	for (int i = 0; i < (int)V.size(); ++i)
		for (int j = 0; j <= i; ++j)
			if (V[i] % V[j] == 0)
				adj[i].push_back(j);

	function<void(int64,int64)> expand;

	expand = [&](int64 i, int64 k){
		if (V[i] == 1 || k == 0) print(V[i]);
		else if (adj[i].size() == 2){
			for (int i = 0; i < k; ++i)
				print(1);
			print(V[i]);
		}
		else{
			for (auto j : adj[i])
				expand(j, k - 1);
		}
	};

	expand(V.size() - 1, k);

	cout << endl;

	return 0;
}