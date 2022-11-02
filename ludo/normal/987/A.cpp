#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for (auto i = (a); i != (b); ++i)
#define rs resize
#define all(v) (v).begin(), (v).end()

map<string, string> mp = {
	{ "purple", "Power" },
	{ "green", "Time" },
	{ "blue", "Space" },
	{ "orange", "Soul" },
	{ "red", "Reality" },
	{ "yellow", "Mind" }
};

set<string> allowed;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (auto kv : mp) allowed.insert(kv.y);

	int N;
	cin >> N;
	while(N--) {
		string S;
		cin >> S;
		allowed.erase(mp[S]);
	}

	cout << allowed.size() << endl;
	for (auto k : allowed) cout << k << endl;

	return 0;
}