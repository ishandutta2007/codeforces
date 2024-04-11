#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> answer(n);
	for (int i = 0; i < n; ++i)
		answer[i] = i;

	for (int i = 0; i < n - k + 1; ++i){
		string s; cin >> s;

		if (s == "NO")
			answer[i + k - 1] = answer[i];
	}

	vector<string> name(26 * 26);

	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j){
			string s = "";
			s += (char)('A' + i);
			s += (char)('a' + j);
			name[i * 26 + j] = s;
		}

	for (int i = 0; i < n; ++i){
		cout << name[ answer[i] ] << " ";
	}
	cout << endl;

	return 0;
}