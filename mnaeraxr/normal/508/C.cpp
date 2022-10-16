#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, t, r;
	cin >> m >> t >> r;

	if (t < r){
		cout << -1 << endl;
		return 0;
	}

	queue<int> Q;
	int last = -100000;
	int ans = 0;

	for (int i = 0; i < m; ++i){
		int v; cin >> v;
		while (!Q.empty() && Q.front() < v - t) Q.pop();
		if (v - last - 1 + (int)Q.size() < r){
			cout << -1 << endl;
			return 0;
		}
		last = v - 1;
		for (int j = v - (r - Q.size()); j < v; ++j) Q.push(j), ++ans;
	}

	cout << ans << endl;

	return 0;
}