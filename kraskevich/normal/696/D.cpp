#include <bits/stdc++.h>

using namespace std;

const int K = 256;

struct vertex {
	int next[K];
	int p;
	char pch;
	int link;
	int go[K];
    int cost;
};
 
const int N = 210;

vertex t[N];
int sz;
 
void init() {
	t[0].p = t[0].link = -1;
	memset (t[0].next, -1, sizeof t[0].next);
	memset (t[0].go, -1, sizeof t[0].go);
	sz = 1;
}
 
void add_string (const string & s, int cost) {
	int v = 0;
	for (size_t i=0; i<s.length(); ++i) {
		char c = s[i];
		if (t[v].next[c] == -1) {
			memset (t[sz].next, -1, sizeof t[sz].next);
			memset (t[sz].go, -1, sizeof t[sz].go);
			t[sz].link = -1;
			t[sz].p = v;
			t[sz].pch = c;
			t[v].next[c] = sz++;
            t[sz].cost = 0;
		}
		v = t[v].next[c];
	}
	t[v].cost += cost;
}
 
int go (int v, char c);
 
int get_link (int v) {
	if (t[v].link == -1)
		if (v == 0 || t[v].p == 0)
			t[v].link = 0;
		else
			t[v].link = go (get_link (t[v].p), t[v].pch);
	return t[v].link;
}
 
int go (int v, char c) {
	if (t[v].go[c] == -1)
		if (t[v].next[c] != -1)
			t[v].go[c] = t[v].next[c];
		else
			t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
	return t[v].go[c];
}

bool was[N];

int calc(int v) {
    if (v == 0)
        return 0;
    if (was[v])
        return t[v].cost;
    was[v] = true;
    t[v].cost += calc(get_link(v));
    return t[v].cost;
}


const long long INF = (long long)2e18;

vector<vector<long long>> unite(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> res(sz, vector<long long>(sz, -INF));
    for (int mid = 0; mid < sz; mid++)
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                res[i][j] = max(res[i][j], a[i][mid] + b[mid][j]);
    return res;
}

vector<vector<long long>> solve(vector<vector<long long>> d, long long len) {
    vector<vector<long long>> res(sz, vector<long long>(sz, -INF));
    for (int i = 0; i < sz; i++)
        res[i][i] = 0;
    while (len > 0) {
        if (len % 2 == 1)
            res = unite(res, d);
        d = unite(d, d);
        len /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    init();
    int n;
    cin >> n;
    long long len;
    cin >> len;
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add_string(s, cost[i]);
    }
    for (int i = 0; i < sz; i++)
        calc(i);
    vector<vector<long long>> d(sz, vector<long long>(sz, -INF));
    for (int i = 0; i < sz; i++)
        d[i][i] = 0;
    for (int i = 0; i < sz; i++)
        for (int c = 'a'; c <= 'z'; c++) {
            int v = go(i, c);
            d[i][v] = t[v].cost;
        }
    d = solve(d, len);
    long long res = 0;
    for (int i = 0; i < sz; i++)
        res = max(res, d[0][i]);
    cout << res << endl;   
    return 0;
}