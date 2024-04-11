#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int total[26];
int seen[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	for (int i = 0; i < (int)s.length(); ++i){
		total[s[i] - 'a']++;
		seen[s[i] - 'a'] = i;
	}

	vector<int> pos;
	for (int i = 0; i < 26; ++i)
		if (total[i] & 1) pos.push_back(i);

	for (int i = 0, j = pos.size() - 1; i < j; ++i, --j){
		total[pos[i]]++; total[pos[j]]--;
	}

	int f = -1;
	if ((int)pos.size() & 1)
		f = pos[pos.size() / 2];

	total[f]--;

	string l = "", r = "";
	for (int i = 0; i < 26; ++i){
		while (total[i]){
			l += (char)('a' + i);
			r = (char)('a' + i) + r;
			total[i] -= 2;
		}
	}

	if (f != -1) l += (char)('a' + f);

	cout << l << r << endl;

	return 0;
}