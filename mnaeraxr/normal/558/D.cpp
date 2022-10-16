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

struct event{
	int64 x;
	int open;

	bool operator<(const event &a) const
	{
		return x < a.x;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<event> V;

	pair<int64,int64> t = {1LL << (n - 1), 1LL << n};

	while(q--){
		int i, ans;
		int64 l, r;
		cin >> i >> l >> r >> ans;
		l <<= n - i;
		r = (r + 1) << (n - i);

		if (ans == 1){
			t.first = max(t.first, l);
			t.second = min(t.second, r);

		}
		else{
			V.push_back({l, 1 });
			V.push_back({r, -1});
		}
	}
	V.push_back({1LL << n, 1});
	V.push_back({1LL << n, -1});

	sort(V.begin(), V.end());

	int64 ans = -1;
	int64 len = 0;
	int64 last = 1LL << (n - 1);

	int o = 0;
	for (int i = 0, j = 0; i < (int)V.size(); i = j)
	{
		if (!o){
			pair<int64,int64> itr = {max(last, t.first), min(V[i].x, t.second)};
			if (itr.second > itr.first){
				len += itr.second - itr.first;
				ans = itr.first;
			}
		}
		last = V[i].x;

		for (; j < (int)V.size() && V[i].x == V[j].x; ++j){
			o += V[j].open;
		}
	}

	if (ans == -1)		cout << "Game cheated!" << endl;
	else if (len > 1)	cout << "Data not sufficient!" << endl;
	else				cout << ans << endl;

	return 0;
}