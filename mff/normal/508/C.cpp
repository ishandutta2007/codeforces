#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int end(int val){
	cout << val << endl;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, t, r; cin >> m >> t >> r;

	queue<int> Q;
	int ans = 0;
	int last = -oo;

	for (int i = 0; i < m; ++i){
		int v; cin >> v;

		while (!Q.empty() && Q.front() + t < v) Q.pop();

		if ((int)Q.size() < r){
			if (v - last - 1 < r - (int)Q.size()) return end(-1);
		}

		for (int j = r - Q.size(); j > 0 ; --j){
			Q.push(v - j), ++ans, last = v - j;
		}

		while (!Q.empty() && Q.front() + t < v) Q.pop();

		if ((int)Q.size() < r) return end(-1);
	}

	return end(ans);

	return 0;
}