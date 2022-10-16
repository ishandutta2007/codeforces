#include <bits/stdc++.h>

using namespace std;

#define MP make_pair

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;

map<pair<char,char>,int> M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s, t;
	cin >> s >> t;

	int cnt = 0;

	for (int i = 0; i < n; ++i){
		if (s[i] != t[i]){
			M[MP(s[i], t[i])] = i;
			++cnt;
		}
	}

	pii best = MP(-1, -1);

	for (auto &p : M)
	{
		pair<char,char> t = MP(p.first.second, p.first.first);
		if (M.count(t)){
			cout << cnt - 2 << endl;
			cout << p.second + 1 << " " << M[t] + 1<< endl;
			return 0;
		}
		if (best.first != -1) continue;
		for (int i = 0; i < 26; ++i){
			t = MP(p.first.second, (char)('a' + i));
			if (M.count(t)){
				best = MP(p.second, M[t]);
				break;
			}
			t = MP((char)('a' + i), p.first.first);
			if (M.count(t)){
				best = MP(p.second, M[t]);
				break;
			}
		}
	}

	if (best.first == -1) cout << cnt << endl << "-1 -1" << endl;
	else{
		cout << cnt - 1 << endl;
		cout << best.first + 1 << " " << best.second  + 1 << endl;
	}

	return 0;
}