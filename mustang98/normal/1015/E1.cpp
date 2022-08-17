#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

char s[max_n][max_n];
char t[max_n][max_n];

int r[max_n][max_n];

int n, m;


int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++i) {
        int cntz = 0;
        for (int j = 0; j < m; ++j) {
            r[i][j] = cntz;
            t[i][j] = '.';
            if (s[i][j] == '*') {
                cntz++;
            } else {
                cntz = 0;
            }
        }
        cntz = 0;
        for (int j = m - 1; j >= 0; --j) {
            r[i][j] = min(r[i][j], cntz);
            if (s[i][j] == '*') {
                cntz++;
            } else {
                cntz = 0;
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        int cntz = 0;
        for (int i = 0; i < n; ++i) {
            r[i][j] = min(r[i][j], cntz);
            if (s[i][j] == '*') {
                cntz++;
            } else {
                cntz = 0;
            }
        }
        cntz = 0;
        for (int i = n - 1; i >= 0; --i) {
            r[i][j] = min(r[i][j], cntz);
            if (s[i][j] == '*') {
                cntz++;
            } else {
                cntz = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        vector<int> b, e;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.' || r[i][j] == 0) continue;
            b.PB(j - r[i][j]);
            e.PB(j + r[i][j]);
        }
        sort(b.begin(), b.end());
        sort(e.begin(), e.end());
        reverse(b.begin(), b.end());
        reverse(e.begin(), e.end());
        int cnt0 = 0;
        for (int j = 0; j < m; ++j) {
            while (b.size() && b.back() == j) {
                cnt0++;
                b.pop_back();
            }
            if (cnt0) {
                t[i][j] = '*';
            }
            while (e.size() && e.back() == j) {
                cnt0--;
                e.pop_back();
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        vector<int> b, e;
        for (int i = 0; i < n; ++i) {
            if (s[i][j] == '.' || r[i][j] == 0) continue;
            b.PB(i - r[i][j]);
            e.PB(i + r[i][j]);
        }
        sort(b.begin(), b.end());
        sort(e.begin(), e.end());
        reverse(b.begin(), b.end());
        reverse(e.begin(), e.end());
        int cnt0 = 0;
        for (int i = 0; i < n; ++i) {
            while (b.size() && b.back() == i) {
                cnt0++;
                b.pop_back();
            }
            if (cnt0) {
                t[i][j] = '*';
            }
            while (e.size() && e.back() == i) {
                cnt0--;
                e.pop_back();
            }
        }
    }
    int cntr =0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] != t[i][j]) {
                cout << "-1";
                exit(0);
            }
            if (s[i][j] != '.' && r[i][j]) {
                cntr++;
            }
        }
    }
    cout << cntr << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '*' && r[i][j]) {
                printf("%d %d %d\n", i + 1, j + 1, r[i][j]);
            }
        }
    }
    return 0;
}