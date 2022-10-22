#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int D[52];
int ID[52];

void shuffle(int l, int m, int r) {
	int buf[52];
	rep(i, N - r) buf[i] = D[r + i];
	rep(i, r - m) buf[N - r + i] = D[m + i];
	rep(i, m - l) buf[N - m + i] = D[l + i];
	rep(i, l) buf[N - l + i] = D[i];
	rep(i, N) D[i] = buf[i];
	rep(i, N) ID[D[i]] = i;
}

int main() {
	cin >> N;
	rep(i, N) { cin >> D[i]; D[i]--; ID[D[i]] = i; }

	vector<vector<int>> ans;

	while (true) {
		int idx = -1;
		rep(i, N - 1) if (ID[i] > ID[i + 1]) idx = i;
		if (idx == -1) break;
		
		int l = ID[idx + 1];
		int m = l + 1;
		int r = ID[idx] + 1;

		while (D[m - 1] + 1 == D[m]) m++;

		vector<int> tmp;
		if (l) tmp.push_back(l);
		if (m - l) tmp.push_back(m - l);
		if (r - m) tmp.push_back(r - m);
		if (N - r) tmp.push_back(N - r);

		ans.push_back(tmp);

		shuffle(l, m, r);
	}

	cout << ans.size() << endl;
	for (auto A : ans) {
		cout << A.size();
		for (int a : A) cout << " " << a;
		cout << endl;
	}

	return 0;
}