#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 300001;


int grundy(int v){
	if (v & 1) return v <= 3;
	int a = grundy(v - 1);
	int b = grundy(v / 2);
	if (a > b) swap(a, b);
	int g = 0;
	if (g == a) ++g;
	if (g == b) ++g;
	return g;
}

int g[maxn];

void b(){
	for (int i = 1; i < 50; ++i){
		int a = g[i - 1];
		int b = i % 2 == 0 ? 0 : a;
		if (a > b) swap(a, b);
		if (g[i] == a) ++g[i];
		if (g[i] == b) ++g[i];
		cout << i << " " << g[i] << endl;
	}
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

//	b();

	int n, k;
	cin >> n >> k;

	if (k % 2 == 0){
		int ans = 0;
		for (int i = 0; i < n; ++i){
			int v; cin >> v;
			if (v > 2) v = (v & 1) ^ 1;
			ans ^= v;
		}

		if (ans) cout << "Kevin" << endl;
		else cout << "Nicky" << endl;
	}
	else{
		int ans = 0;
		for (int i = 0; i < n; ++i){
			int v; cin >> v;
			ans ^= grundy(v);
		}
		if (ans) cout << "Kevin" << endl;
		else cout << "Nicky" << endl;
	}

	return 0;
}