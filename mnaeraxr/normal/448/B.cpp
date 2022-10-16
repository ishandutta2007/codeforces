#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

bool isSubsequence(string a, string b){
	int p = 0;
	for (auto c : b){
		while (p < (int)a.length() && a[p] != c)
			++p;

		if (p == (int)a.length())
			return false;

		p++;
	}

	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s, t;
	cin >> s >> t;

	if (isSubsequence(s, t)){
		cout << "automaton" << endl;
		return 0;
	}

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	if (isSubsequence(s, t)){
		if (s.length() == t.length()){
			cout << "array" << endl;
		}
		else{
			cout << "both" << endl;
		}

		return 0;
	}

	cout << "need tree" << endl;

	return 0;
}