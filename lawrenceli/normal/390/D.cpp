#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

typedef pair<int, int> pii;

int n, m, k;
vector<vector<pii> > v;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> k;

    int r = 1, c = 1;
    while (k--) {
        v.push_back(vector<pii>());
        for (int i=1; i<=r; i++)
            v.back().push_back(pii(i, 1));
        for (int i=2; i<=c; i++)
            v.back().push_back(pii(r, i));

        if (k == 0) break;
        do {
            if (c == 1) c = r+1, r = 1;
            else r++, c--;
        } while (r > n || c > m);
    }

    int ans = 0;
    for (int i=0; i<v.size(); i++)
        ans += v[i].size();

    cout << ans << '\n';
    for (int i=v.size()-1; i>=0; i--) {
        for (int j=0; j<v[i].size(); j++)
            cout << '(' << v[i][j].first << ',' << v[i][j].second << ") ";
        cout << '\n';
    }

    return 0;
}