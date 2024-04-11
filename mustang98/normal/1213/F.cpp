#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int p1[max_n];
int p2[max_n];

int pos[max_n];

set<pair<int, int>> s;
char ans[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        scanf("%d", p1 + i);
        --p1[i];
        pos[p1[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", p2 + i);
        --p2[i];
    }
    for (int i = 0; i < n; ++i) {
        s.emplace(i, i);
    }
    for (int i = 0; i + 1 < n; ++i) {
        int a = p2[i], b = p2[i + 1];
        if (pos[a] > pos[b]) {
            s.emplace(pos[b], pos[a]);
        }
    }
    vector<pair<int, int>> v;
    while (!s.empty()) {
        pair<int, int> cur = *s.begin();
        s.erase(s.begin());
        while(!s.empty() && s.begin()->F <= cur.S) {
            cur.S = max(cur.S, s.begin()->S);
            s.erase(s.begin());
        }
        v.push_back(cur);
    }

    if (v.size() < k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    char cur = 'a';
    for (pair<int, int> ss : v) {
        for (int i = ss.F; i <= ss.S; ++i) {
            ans[p1[i]] = cur;
        }
        if (cur != 'z') ++cur;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
    return 0;
}