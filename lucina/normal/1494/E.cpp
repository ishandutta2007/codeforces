#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, m;


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    map <pair <int, int>, char> setik;
    int cnt_bi = 0;
    int ct_same = 0;

    while (m --) {
        char cmd;
        cin >> cmd;

        if (cmd == '?') {
            int k;
            cin >> k;
            bool ok = false;
            if (k % 2) {
                if (cnt_bi) ok = true;
            } else {
                if (ct_same) ok = true;
            }
            cout << (ok ? "YES" : "NO") << '\n';

        } else if (cmd == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            setik[make_pair(u, v)] = c;
            if (setik.count(make_pair(v, u))) {
                cnt_bi += 1;
                if (setik[make_pair(u, v)] == setik[make_pair(v, u)])
                        ct_same += 1;
            }
        } else if (cmd == '-') {
            int u, v;
            cin >> u >> v;
            if (setik.count(make_pair(v, u))) {
                    cnt_bi -= 1;
                if (setik[make_pair(u, v)] == setik[make_pair(v, u)])
                    ct_same -= 1;
            }
            setik.erase(make_pair(u, v));

        } else throw;
    }
}