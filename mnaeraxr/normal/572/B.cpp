#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

map<int,int> B, S;

void print(map<int,int> &T, int tot, char c){
	vector<pii> toprint;
	for (auto val : T){
		toprint.push_back({abs(val.first), val.second});
		if (--tot == 0) break;
	}

	if (c == 'S') reverse(toprint.begin(), toprint.end());

	for (auto v : toprint)
		cout << c << " " << v.first << " " << v.second << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; ++i){
		string c;
		int p, q;
		cin >> c >> p >> q;
		if (c == "B")
			B[-p] += q;
		else
			S[p] += q;
	}

	print(S, s, 'S');
	print(B, s, 'B');

	return 0;
}