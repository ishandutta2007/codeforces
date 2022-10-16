#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = (int)3e5 + 10;

int64 l[maxn];
int le[maxn], ri[maxn];
int stk[maxn];
int top;

int64 solve(int b, int e){
//	cout << b << " " << e << endl;
//	for (int i = b; i <= e; ++i)
//		cout << l[i] << " ";
//	cout << endl;
//	cout << endl;
	int top = 0;
	for (int i = b; i <= e; ++i){
		while (top && l[stk[top - 1]] < l[i]) --top;

		if (top) le[i] = stk[top - 1];
		else le[i] = b - 1;

		stk[top++] = i;
	}
/*
10 1
1 5 2 9 1 3 4 2 1 7
7 10
 */
	top = 0;
	for (int i = e; i >= b; --i){
		while (top && l[stk[top - 1]] <= l[i]) --top;

		if (top) ri[i] = stk[top - 1];
		else ri[i] = e + 1;

//		cout << "ri: " << i << " " << ri[i] << " " << top << endl;

		stk[top++] = i;
	}

	int64 ans = 0;
	for (int i = b; i <= e; ++i){
//		cout << le[i] << " " << ri[i] << endl;
		ans += l[i] * (i - le[i]) * (ri[i] - i);
	}

//	cout << ans << endl;
//	exit(0);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	int64 v; cin >> v;

	for (int i = 0; i < n - 1; ++i){
		int64 vv; cin >> vv;
		l[i] = abs(vv - v);
		v = vv;
	}

	while (q--){
		int u, v; cin >> u >> v;
		cout << solve(u - 1, v - 2) << endl;
	}

	return 0;
}