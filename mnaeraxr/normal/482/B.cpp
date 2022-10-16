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

vector<int> L, R, Q;
pair<int, int> ST[MAXN << 2]; // value, lazy

void down_lazy(int p)
{
	int left = p << 1;
	int right = left | 1;
	ST[left].first |= ST[p].second;
	ST[left].second |= ST[p].second;
	ST[right].first |= ST[p].second;
	ST[right].second |= ST[p].second;
	ST[p].second = 0;
}

void update(int p, int b, int e, int x, int y, int v)
{
	if (x <= b && e <= y)
	{
		ST[p].first |= v;
		ST[p].second |= v;
	}
	else
	{
		if (ST[p].second) down_lazy(p);

		int mid = (b + e) >> 1;
		int left = p << 1;
		int right = left | 1;

		if (y <= mid)
			update(left, b, mid, x, y, v);
		else if (mid + 1 <= x)
			update(right, mid + 1, e, x, y, v);
		else
		{
			update(left, b, mid, x, y, v);
			update(right, mid + 1, e, x, y, v);
		}

		ST[p].first = ST[left].first & ST[right].first;
	}
}

int query(int p, int b, int e, int x, int y)
{
	if (x <= b && e <= y)
		return ST[p].first;
	else
	{
		if (ST[p].second) down_lazy(p);

		int mid = (b + e) >> 1;
		int left = p << 1;
		int right = left | 1;

		if (y <= mid)
			return query(left, b, mid, x, y);
		else if (mid + 1 <= x)
			return query(right, mid + 1, e, x, y);
		else
			return query(left, b, mid, x, y) & query(right, mid + 1, e, x, y);
	}
}




int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int l, r, q;
		cin >> l >> r >> q;
		l--; r--;
		update(1, 0, N - 1, l, r, q);
		L.push_back(l);
		R.push_back(r);
		Q.push_back(q);
	}

	bool valid = true;

	for (int i = 0; i < M && valid; ++i)
		if (query(1, 0, N - 1, L[i], R[i]) != Q[i]) valid = false;


	if (valid)
	{
		cout << "YES" << endl;
		for (int i = 0; i < N; ++i)
			cout << query(1, 0, N - 1, i, i) << " ";
		cout << endl;
	}
	else
		cout << "NO" << endl;

	return 0;
}