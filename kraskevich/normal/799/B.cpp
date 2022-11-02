#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)2e9;
const int N = 3;

multiset<int> at[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        at[a[i] - 1][b[i] - 1].insert(p[i]);
    int m;
    cin >> m;
    for (int t = 0; t < m; t++) {
        int c;
        cin >> c;
        c--;
        int ii = -1;
        int jj = -1;
        int val = INF;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if ((i == c || j == c) && at[i][j].size()) {
                    if (*at[i][j].begin() < val) {
                        val = *at[i][j].begin();
                        ii = i;
                        jj = j;
                    }
                }
        if (val == INF) {
            cout << "-1\n";
            continue;
        }
        at[ii][jj].erase(at[ii][jj].begin());
        cout << val << "\n";
    }
}