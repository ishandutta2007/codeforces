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

	string s; cin >> s;

	map<char,int> M;

	for (auto c : s){
		M[c]++;
	}

	int total = min( {M['B'], M['u'] / 2, M['a'] / 2, M['l'], M['b'], M['s'], M['r']} );

	cout << total << endl;

	return 0;
}