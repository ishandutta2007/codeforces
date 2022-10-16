#include <bits/stdc++.h>

using namespace std;

int p[100005];
int u[100005];
int n;
int nxt(int x) {
    return x % n + 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    for (int i = 2; i <= 10000; ++i) if (!p[i])
        for (int j = i + i; j <= 10000; j += i) p[j] = 1;
    cin >> n;
    vector <pair <int, int> > ans;
    for (int i = 1; i <= n; ++i) ans.push_back(make_pair(i, nxt(i)));
    int id = 1;
    while (p[ans.size()]) {
        while (u[id]) id = nxt(id);
        int jd = nxt(nxt(id));
        while (u[jd]) jd = nxt(jd);
        ans.push_back(make_pair(id, jd));
        u[id] = u[jd] = 1;
    }
    cout << ans.size() << endl;
    for (auto x: ans) cout << x.first << ' ' << x.second << endl;
    return 0;
}