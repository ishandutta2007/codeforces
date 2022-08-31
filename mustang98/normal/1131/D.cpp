#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2011, inf = 1000111222;

char f[max_n][max_n];
int n, m;
string s;
char cs[max_n];
vector<int> v[max_n];
int in[max_n];

void NO() {
    cout << "No" << endl;
    exit(0);
}

vector<int> g[max_n];
int allin[max_n];
int cnt[max_n];
int col[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n + m; ++i) {
        v[i].PB(i);
        in[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", cs);
        s = string(cs);
        for (int j = 0; j < s.size(); ++j) {
            f[i][n + j] = s[j];
            f[n + j][i] = s[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n; j < n + m; ++j) {
            if (f[i][j] == '=') {
                int i1 = in[i];
                int i2 = in[j];
                if (i1 == i2) continue;
                if (v[i1].size() < v[i2].size()) {
                    swap(i1, i2);
                }
                for (int k = 0; k < v[i2].size(); ++k) {
                    int val = v[i2][k];
                    in[val] = i1;
                    v[i1].PB(val);
                }
                v[i2].clear();
            }
        }
    }
    for (int i = 0; i < n + m; ++i) {
        vector<int>& c = v[i];
        for (int a : c) {
            for (int b : c) {
                if (a < n && b < n) continue;
                if (a >= n && b >= n) continue;
                if (f[a][b] != '=') {
                    NO();
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = n; j < n + m; ++j) {
            char c = f[i][j];
            int a = in[i];
            int b = in[j];
            if (a == b) continue;
            if (c == '<') {
                g[a].PB(b);
                allin[b]++;
            } else {
                g[b].PB(a);
                allin[a]++;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n + m; ++i) {
        if (v[i].size() == 0) continue;
        if (allin[i] == 0) {
            col[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int to : g[cur]) {
            col[to] = max(col[to], col[cur] + 1);
            cnt[to]++;
            if (cnt[to] == allin[to]) {
                q.push(to);
            }
        }
    }
    for (int i = 0; i < n + m; ++i) {
        if (v[i].size() == 0) continue;
        if (cnt[i] != allin[i]) {
            NO();
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) {
        cout << col[in[i]] + 1 << ' ';
    }
    cout << endl;
    for (int i = n; i < n + m; ++i) {
        cout << col[in[i]] + 1 << ' ';
    }
    cout << endl;

    return 0;
}