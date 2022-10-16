#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

void mix(string &s, string p){
	if (s.length() != p.length()){
		cout << "No" << endl;
		exit(0);
	}

	for (int i = 0; i < (int)s.length(); ++i)
		if (s[i] != p[i]) s[i] = '?';
}

bool match(string s, string p){
	if (s.length() != p.length())
		return false;

	for (int i = 0; i < (int)s.length(); ++i)
		if (s[i] != p[i] && s[i] != '?') return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<string> v(n);

	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}

	vector<int> D;

	for (int j = 0; j < m; ++j){
		int val; cin >> val;
		val--; D.push_back(val);
	}

	string s = v[D[0]];

	for (auto p : D){
		mix(s, v[p]);
		v[p] = "";
	}

	for (int i = 0; i < n; ++i){
		if (match(s, v[i])){
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	cout << s << endl;

	return 0;
}