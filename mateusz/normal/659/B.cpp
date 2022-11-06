#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, region, points;
string lol;
vector<pair<int, string> > V[N];

bool cmp(const pair<int, string> &a, const pair<int, string> &b) {
    return a.first > b.first;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> lol >> region >> points;
        V[region].push_back({points, lol});
    }

    for (int i = 1; i <= m; i++) {
        sort(V[i].begin(), V[i].end(), cmp);
        if (V[i].size() > 2 && V[i][1].first == V[i][2].first) {
            cout << "?\n";
        } else {
            cout << V[i][0].second << " " << V[i][1].second << endl;
        }
    }

    return 0;
}