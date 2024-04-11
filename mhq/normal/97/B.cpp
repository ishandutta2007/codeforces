#include <bits/stdc++.h>
using namespace std;
int n;
vector < pair < int, int > > q;
vector < pair < int, int > > solve(vector < pair < int, int > > t) {
    //cout << t.size() << endl;
    vector < pair < int, int > > t1;
    //cout << t1.size() << endl;
    vector < pair < int, int > > t2;
    vector < pair < int, int > > ans;
    if (t.size() <= 1) return t1;
    sort(t.begin(), t.end());
    int mid = (t.size()) / 2;
    int prv = (int)1e9 + 10;
    int x = t[mid].first;
    map < int, int > y;
    for (int i = 0; i < t.size(); i++) {
        if (y[t[i].second] == 0) {
            y[t[i].second] =  1;
            ans.push_back(make_pair(x, t[i].second));
        }
        if (t[i].first < x) {
            t1.push_back(t[i]);
        }
        if (t[i].first > x) {
            t2.push_back(t[i]);
        }
    }
    vector < pair < int, int > > p1 = solve(t1);
    vector < pair < int, int > > p2 = solve(t2);
    for (int i = 0; i < p1.size(); i++) {
        ans.push_back(p1[i]);
    }
    for (int i = 0; i < p2.size(); i++) {
        ans.push_back(p2[i]);
    }
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        q.push_back(make_pair(x, y));
    }
    vector < pair < int, int > > p = solve(q);
    vector < pair < int, int > > n;
    pair < int, int > prv = make_pair((int)1e9 + 10, (int)1e9 + 10);
    for (int i = 0; i < q.size(); i++) {
        p.push_back(q[i]);
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == prv) continue;
        else {
            n.push_back(p[i]);
            prv = p[i];
        }
    }
    cout << n.size() << '\n';
    for (int i = 0; i < n.size(); i++) {
        cout << n[i].first << " " << n[i].second << '\n';
    }
    return 0;
}