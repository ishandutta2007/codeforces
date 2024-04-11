#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000;
const int N = 401;
const int K = 51;

int old[N][N];
int cur[N][N];

vector<int> all;

int get_id(int x) {
    return lower_bound(all.begin(), all.end(), x) - all.begin();
}

const int T = N * N / 2;

int tree1[4 * T + 10];
int tree2[4 * T + 10];

void put1(int i, int tl, int tr, int pos, int val) {
    if (tl == pos && tr == pos) {
	tree1[i] = max(tree1[i], val);
	return;
    }
    int m = (tl + tr) / 2;
    if (pos <= m)
	put1(2 * i + 1, tl, m, pos, val);
    else
	put1(2 * i + 2, m + 1, tr, pos, val);
    tree1[i] = max(tree1[i], val);
}

int get_max1(int i, int tl, int tr, int l, int r) {
    if (l == tl && r == tr)
	return tree1[i];
    int ml = -INF;
    int mr = -INF;
    int m = (tl + tr) / 2;
    if (l <= m)
	ml = tree1[2 * i + 1];
    if (r > m)
	mr = get_max1(2 * i + 2, m + 1, tr, max(m + 1, l), r);
    return max(ml, mr);
}

void put2(int i, int tl, int tr, int pos, int val) {
    if (tl == pos && tr == pos) {
	tree2[i] = max(tree2[i], val);
	return;
    }
    int m = (tl + tr) / 2;
    if (pos <= m)
	put2(2 * i + 1, tl, m, pos, val);
    else
	put2(2 * i + 2, m + 1, tr, pos, val);
    tree2[i] = max(tree2[i], val);
}

int get_max2(int i, int tl, int tr, int l, int r) {
    if (l == tl && r == tr)
	return tree2[i];
    int ml = -INF;
    int mr = -INF;
    int m = (tl + tr) / 2;
    if (l <= m)
	ml = get_max2(2 * i + 1, tl, m, l, min(r, m));
    if (r > m)
	mr = tree2[2 * i + 2];
    return max(ml, mr);
}

int f[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    //n = 400;
    //k = 50;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
	cin >> a[i];
	//a[i] = rand() % 10000;
    for (int i = 0; i < n; i++) {
	int s = 0;
	for (int j = i; j < n; j++) {
	    s += a[j];
	    all.push_back(s);
	}
    }
    sort(all.begin(), all.end());
    unique(all.begin(), all.end());
    for (int i = 0; i < n; i++) {
	int s = 0;
	for (int j = i; j < n; j++) {
	    s += a[j];
	    f[i][j] = get_id(s);
	}
    }
    for (int i = 0; i < n; i++)
	for (int j = 0; j <= i; j++)
	    old[j][i] = 0.0;
	
    for (int cnt = 2; cnt <= k; cnt++) {
	fill(tree1, tree1 + 4 * T + 10, -INF);
	fill(tree2, tree2 + 4 * T + 10, -INF);
	for (int L = 0; L < n; L++) {
	    int curS = 0;
	    for (int R = L; R < n; R++) {
		curS += a[R];
		int pos = f[L][R];
		int low = get_max1(0, 0, T - 1, 0, pos) + curS;
		int high = get_max2(0, 0, T - 1, pos, T - 1) - curS;
		cur[L][R] = max(-INF, max(low, high));
	    }
	    curS = 0;
	    for (int R = L; R >= 0; R--) {
		curS += a[R];
		int pos = f[R][L];
		if (old[R][L] == -INF)
		    continue;
		put1(0, 0, T - 1, pos, old[R][L] - curS);
		put2(0, 0, T - 1, pos, old[R][L] + curS);
	    }
	}
	for (int i = 0; i < n; i++)
	    for (int j = 0; j <= i; j++)
		old[j][i] = cur[j][i];
    }
    int res = -INF;
    for (int i = 0; i < n; i++)
	for (int j = i; j < n; j++)
	    res = max(res, old[i][j]);	
    cout << res << endl;
    return 0;
}