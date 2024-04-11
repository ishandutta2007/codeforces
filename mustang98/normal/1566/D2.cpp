#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 311, inf = 1000111222;

int a[max_n * max_n];
int n, m;
bool cmp(int i, int j) {
    if (a[i] == a[j]) {
        return i > j;
    }
    return a[i] < a[j];
}

vector<int> v;

void proc(int from, int to) {
    vector<int> v1;
    for (int i = from; i <= to; ++i) {
        v1.PB(v[i]);
    }
    sort(v1.begin(), v1.end());
    int sr = from / m;
    int sc = from % m;
    int fr = to / m;
    int fc = to % m;
    if (sr == fr) {
        return;
    }
    int csm = m - sc;
    int cbig = fc + 1;
    vector<int> vsm, vbig;
    reverse(v1.begin(), v1.end());
    for (int i = 0; i < csm; ++i) {
        vsm.PB(v1.back());
        v1.pop_back();
    }
    reverse(v1.begin(), v1.end());
    for (int i = 0; i < cbig; ++i) {
        vbig.PB(v1.back());
        v1.pop_back();
    }
    sort(vsm.begin(), vsm.end());
    sort(vbig.begin(), vbig.end());
    sort(v1.begin(), v1.end());
    reverse(vsm.begin(), vsm.end());
    reverse(vbig.begin(), vbig.end());
    reverse(v1.begin(), v1.end());
    int cur = from;
    for (int x : vsm) {
        v[cur++] = x;
    }
    for (int x : v1) {
        v[cur++] = x;
    }
    for (int x : vbig) {
        v[cur++] = x;
    }
}

int vis[max_n][max_n];
int pos[max_n * max_n];
int calc() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            vis[i][j] = 0;
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        pos[v[i]] = i;
    }
    ll ans = 0;
    for (int i = 0; i < n * m; ++i) {
        int r = pos[i] / m;
        int c = pos[i] % m;
        for (int j = 0; j < c; ++j) {
            ans += vis[r][j];
        }
        vis[r][c] = 1;
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        v.clear();
        for (int i = 0; i < n * m; ++i) {
            cin >> a[i];
            v.PB(i);
        }
        sort(v.begin(), v.end(), cmp);
        int st = 0;
        for (int i = 1; i < v.size(); ++i) {
            int cur = v[i], pr = v[i - 1];
            if (a[cur] == a[pr]) {
                continue;
            }
            proc(st, i - 1);
            st = i;
        }
        proc(st, v.size() - 1);
        cout << calc() << "\n";
    }

    return 0;
}