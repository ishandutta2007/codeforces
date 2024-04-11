#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define fill_to_n(a,n,k) iota(a,a+n,k)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, k, p[200005], act = 1, j;
	vi res;

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> p[i];
	}

	stack<int> st;

	st.push(n+1);
	for (int i = 0; i < k; i++) {
		st.push(p[i]);

		while (st.size() && st.top() == act) {
			st.pop();
			act++;
		}
	}

	j = st.top() - 1;
	for (int i = k; i < n; i++) {
		bool f = 0;

		res.push_back(j);
		st.push(j--);

		while (st.size() && st.top() == act) {
			act++;
			st.pop();
			f = 1;
		}

		if (f && st.size())
			j = st.top() - 1;
	}

	if (act == n + 2) {
		for (int i = 0; i < k; i++)
			cout << p[i] << " ";
		for (int x : res)
			cout << x << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}