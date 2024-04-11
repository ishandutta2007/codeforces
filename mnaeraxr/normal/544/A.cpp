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

	int n; cin >> n;

	string s; cin >> s;

	vector<int> count(26);

	for (auto c : s) count[c - 'a'] = 1;
	int tot = 0; for (int i = 0; i < 26; ++i) tot += count[i];

	if (tot < n){
		cout << "NO" << endl;
	}
	else{
		cout << "YES";

		for (auto c : s){
			if (n && count[c - 'a']){
				count[c - 'a'] = 0;
				n--;
				cout << endl;
			}
			cout << c;
		}
		cout << endl;
	}

	return 0;
}