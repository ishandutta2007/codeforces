#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)x.size())
#define DB(x) cout << #x << "=" << x << endl
#define endl '\n'
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1 << 30;

bool compare1(pii a, pii b)
{

	if (a.second != b.second)
		return a.second > b.second;
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> V(n);
	for (int i = 0; i < n; ++i) cin >> V[i];

	stack<pii> S;
	vector<int> L(n), R(n);

	S.push(MP(-1, -1));
	for (int i = 0; i < n; ++i){
		while (S.top().first >= V[i]) S.pop();
		L[i] = i - S.top().second;
		S.push(MP(V[i], i));
	}

	S = stack<pii>();
	S.push(MP(-1,n));

	for (int i = n - 1; i >= 0; --i){
		while (S.top().first >= V[i]) S.pop();
		R[i] = S.top().second - i;
		S.push(MP(V[i],i));
	}

	vector<pii> T(n);
	for (int i = 0; i < n; ++i){
		T[i] = MP(R[i] + L[i] - 1, V[i]);
	}

	sort(T.begin(), T.end(), compare1);

	vector<int> ans(n);

	int val = 0;

	for (auto cur : T){
		//cout << cur.first << " " << cur.second << endl;
		while (val < cur.first) ans[val++] = cur.second;
	}

	for (auto v : ans) cout << v << " ";
	cout << endl;

	return 0;
}