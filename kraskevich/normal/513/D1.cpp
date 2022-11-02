#include <bits/stdc++.h>

using namespace std;

const int N = 111;

vector<int> lroot;
vector<int> lc;
vector<int> rroot;
vector<int> rc;
vector<int> od;

int dp[N][N];
int split[N][N];

int calc(int L, int R) {
    if (L > R)
	return true;
    if (dp[L][R] != -1)
	return dp[L][R];
    if (L == R) {
	for (int i = 0; i < lroot.size(); i++)
	    if (lroot[i] == L)
		return dp[L][R] = 0;
	for (int i = 0; i < rroot.size(); i++)
	    if (rroot[i] == L)
		return dp[L][R] = 0;
	return dp[L][R] = 1;
    }
    for (int mid = L; mid <= R; mid++) {
	bool ok = true;
	for (int i = 0; i < lroot.size(); i++)
	    if (lroot[i] == L && (lc[i] <= L || lc[i] >= mid + 1))
		ok = false;
	for (int i = 0; i < rroot.size(); i++)
	    if (rroot[i] == L && (rc[i] <= mid || rc[i] > R))
		ok = false;
	if (ok)
	    ok = ok && calc(L + 1, mid) && calc(mid + 1, R);
	if (ok) {
	    split[L][R] = mid;
	    return dp[L][R] = 1;
	}
    }
    return dp[L][R] = 0;
}

void rec(int l, int r) {
    if (l > r)
	return;
    if (l == r) {
	od.push_back(l);
	return;
    }
    rec(l + 1, split[l][r]);
    od.push_back(l);
    rec(split[l][r] + 1, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < c; i++) {
	int a, b;
	cin >> a >> b;
	a--;
	b--;
	string s;
	cin >> s;
	if (s == "LEFT") {
	    lroot.push_back(a);
	    lc.push_back(b);
	} else {
	    rroot.push_back(a);
	    rc.push_back(b);
	} 
    }
    for (int l = 0; l < n; l++)
	for (int r = 0; r < n; r++)
	    dp[l][r] = -1;
    if (calc(0, n - 1) == 0) {
	cout << "IMPOSSIBLE" << endl;
	return 0;
    }
    rec(0, n - 1);
    for (int elem : od)
	cout << elem + 1 << " ";
    cout << endl;
    return 0;
}