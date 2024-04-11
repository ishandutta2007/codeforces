#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

pii tot[28];
bool mk[28];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s; cin >> s;
	int k; cin >> k;

	for (auto c : s)
		tot[c - 'a'].first++;

	for (int i = 0; i < 26; ++i) tot[i].second = i, mk[i] = true;
	sort(tot, tot + 26);

	int ans = 26;

	for (int i = 0; i < 26; ++i){
		if (tot[i].first <= k){
			k -= tot[i].first;
			mk[tot[i].second] = false;
			ans--;
		}
		else
			break;
	}

	cout << ans << endl;
	for (auto c : s){
		if (mk[c - 'a']) cout << c;
	}
	cout << endl;

	return 0;
}