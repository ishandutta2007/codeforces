#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;

int it = 0;

map<vector<int>,int> memo;

int query(int x1, int y1, int x2, int y2){
	vector<int> v = {x1, y1, x2, y2};

	if (memo.count(v))
		return memo[v];

	assert(++it <= 200);

	cout << "? ";

	cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	cout.flush();

	int ans; cin >> ans;
	memo[v] = ans;

	return ans;
}

int n;

int calc1(bool horizontal, int total){
	int lo = 1, hi = n + 1;

	while (lo + 1 < hi){
		int m = (lo + hi) / 2, t;

		if (horizontal)
			t = query(m, 1, n, n);
		else
			t = query(1, m, n, n);

		if (t < total) hi = m;
		else lo = m;
	}

	return lo;
}


int calc2(bool horizontal, int total){
	int lo = 0, hi = n;

	while (lo + 1 < hi){
		int m = (lo + hi) / 2, t;

		if (horizontal)
			t = query(1, 1, m, n);
		else
			t = query(1, 1, n, m);

		if (t < total) lo = m;
		else hi = m;
	}

	return hi;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int x1 = calc1(true, 2);
	int x2 = calc2(true, 1);
	int x3 = calc1(true, 1);
	int x4 = calc2(true, 2);

	int y1 = calc1(false, 2);
	int y2 = calc2(false, 1);
	int y3 = calc1(false, 1);
	int y4 = calc2(false, 2);

	int X1, X2, X3, X4, Y1, Y2, Y3, Y4;

	for (int i = 0; i < 8; ++i){
		int X1 = x1;
		int X3 = x3;

		if (i & 1){
			Y1 = y1;
			Y3 = y3;
		}
		else{
			Y1 = y3;
			Y3 = y1;
		}

		if (i & 2){
			X2 = x2;
			X4 = x4;
		}
		else{
			X2 = x4;
			X4 = x2;
		}

		if (i & 4){
			Y2 = y2;
			Y4 = y4;
		}
		else{
			Y2 = y4;
			Y4 = y2;
		}

		if (X1 > X2 || Y1 > Y2 || X3 > X4 || Y3 > Y4)
			continue;

		bool r1 = query(X1, Y1, X2, Y2) == 1;
		bool r2 = query(X3, Y3, X4, Y4) == 1;

		if (r1 && r2){
			cout << "! ";
			cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << " ";
			cout << X3 << " " << Y3 << " " << X4 << " " << Y4 << endl;
			cout.flush();
			exit(0);
//			break;
		}
	}


	return 0;
}