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

	string s; cin >> s;

	int n; cin >> n;

	int64 answer = 0, m = 0, counter = 1;

	vector<int64> alph(26);

	for (int i = 0; i < 26; ++i){
		cin >> alph[i];
		m = max(m, alph[i]);
	}

	for (auto c : s){
		answer += (counter++) * alph[c - 'a'];
	}

	for (int i = 0; i < n; ++i)
		answer += m * (counter++);

	cout << answer << endl;

	return 0;
}