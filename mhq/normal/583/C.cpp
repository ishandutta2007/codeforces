#include <bits/stdc++.h>
using namespace std;
vector < int > cur;
set < pair < int, int > > s;
int n;
void upd(int x, int num = 1) {
    auto it = s.lower_bound(make_pair(x, 0));
    int cnt = (*it).second;
    if (cnt == num) s.erase(it);
    else {
        s.erase(it);
        s.insert(make_pair(x, cnt - num));
    }
}
int gcd(int x, int y) {
    while (x > 0 && y > 0) {
        if (x < y) swap(x, y);
        x %= y;
    }
    return x + y;
}
int main() {
    ios_base::sync_with_stdio(false);
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n * n; i++) {
        int x;
        cin >> x;
        auto it = s.lower_bound(make_pair(x, 0));
        if ((it != s.end()) && (*it).first == x) {
            int cnt = (*it).second;
            s.erase(it);
            s.insert(make_pair(x, cnt + 1));
        }
        else s.insert(make_pair(x, 1));
    }
    auto it = s.end();
    it--;
    int f1 = (*it).first;
    upd(f1);
    cur.push_back(f1);
    while (!s.empty()) {
        auto it = s.end();
        it--;
        int x = (*it).first;
        upd(x, 1);
        for (int i = 0; i < cur.size(); i++) {
            upd(gcd(x, cur[i]), 2);
        }
        cur.push_back(x);
    }
    for (int i = 0; i < cur.size(); i++) cout << cur[i] << " ";
    return 0;
}