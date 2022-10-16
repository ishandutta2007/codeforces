#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef int int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;
const int mod = 1000000007;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;

	int cur = 0;

	bool ok = true;

	for (auto c : s){
		int v = c - 'a';

		if (v == cur) cur++;
		else if (v > cur){
			ok = false;
			break;
		}
	}

	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}