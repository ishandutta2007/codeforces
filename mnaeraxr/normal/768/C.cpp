#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

const int MAX = 1024;

int freq[MAX];
int tfreq[MAX];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	const int MAX = 1 << 10;

	int n, k, x;
	cin >> n >> k >> x;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		freq[v]++;
	}

	for (int i = 0; i < k; ++i){

		for (int j = 0, p = 0; j < MAX; ++j){
			int b = freq[j] / 2, a = freq[j] - b;

			if (p & 1) swap(a, b);

			tfreq[j] += b;
			tfreq[j ^ x] += a;

			p ^= freq[j] & 1;
		}

		for (int j = 0; j < MAX; ++j){
			freq[j] = tfreq[j];
			tfreq[j] = 0;
		}
	}

	int mn_pos = 0, mx_pos = MAX - 1;

	while (!freq[mn_pos]) mn_pos++;
	while (!freq[mx_pos]) mx_pos--;

	cout << mx_pos << " " << mn_pos << endl;

//	cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;

	return 0;
}