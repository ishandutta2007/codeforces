#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100;

bool poss[MAXN + 1] = {};
int idxref[MAXN + 1];

int n, a[MAXN];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	poss[0] = true;
	idxref[0] = 0;

	for (int i = 0; i < n; i++) {
		// i: initially done
		if (!poss[i]) continue;
		int s = 0;
		for (int j = i + 1; j <= n; j++) {
			// j: new amount done.
			s += a[j - 1];
			if (s != 0) {
				poss[j] = true;
				idxref[j] = i;
			}
		}
	}
	
	if (!poss[n]) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	vector<int> st;
	int cur = n;
	while (cur) {
		cur = idxref[cur];
		st.push_back(cur);
	}
	st.pop_back();

	reverse(st.begin(), st.end());

	cout << (st.size() + 1) << endl;
	cout << "1 ";
	for (int i : st) {
		cout << i << "\n" << (i + 1) << " ";
	}
	cout << n << endl;
	return 0;
}