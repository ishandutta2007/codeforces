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

void run() {
	string S;
	getline(cin, S);
	int cnt = 0;
	vector<string> v = { "Danil", "Olya", "Slava", "Ann", "Nikita" };
	for (string s : v) {
		int it = S.find(s);
		cnt += it != string::npos;
		if (it != string::npos) {
			cnt += S.find(s, it + s.size())  != string::npos;
		}
	}
	if (cnt == 1) {
		cout << "YES" << endl;
	} else cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	run();

	return 0;
}