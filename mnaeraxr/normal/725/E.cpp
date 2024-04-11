#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

bool solve(int c, map<int,int> &freq){
	int big = 2000000;

	while (c){
		auto it = freq.upper_bound(min(big, c));
		if (it == freq.begin()) return false;
		it--;

		big = it->first - 1;

		int tot = min(c / it->first, it->second);
		c -= it->first * tot;
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c, n;
	cin >> c >> n;

	map<int,int> freq;

	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		freq[v]++;
	}

	for (int i = 0; i < c; ++i){
		freq[i]++;

		if (!solve(c, freq)){
			cout << i << endl;
			return 0;
		}

		freq[i]--;
		if (freq[i] == 0) freq.erase(i);
	}

	cout << "Greed is good" << endl;

	return 0;
}