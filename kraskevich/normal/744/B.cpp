#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1000 * 1000 * 1000;

vector<int> res;
int n;

void check(const vector<int> v) {
    if (v.size() == 0)
        return;
    cout << v.size() << endl;
    for (int x : v)
        cout << x + 1 << " ";
    cout << endl;
    vector<int> cur(n);
    for (int i = 0; i < n; i++)
        cin >> cur[i];
    set<int> s;
    for (int x : v)
        s.insert(x);
    for (int i = 0; i < n; i++)
        if (s.count(i) == 0)
            res[i] = min(res[i], cur[i]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    res.assign(n, INF);
    for (int rep = 0; rep < 10; rep++) {
        vector<int> a, b;
        for (int i = 0; i < n; i++)
            if (i & (1 << rep))
                a.push_back(i);
             else
                b.push_back(i);
        check(a);
        check(b);        
    }
    cout << -1 << endl;
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}