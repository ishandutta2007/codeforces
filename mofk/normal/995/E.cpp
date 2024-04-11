#include <bits/stdc++.h>

using namespace std;

int random(int p) {
    long long x = 1ll * rand() * rand() + rand();
    return x % p;
}

vector <int> solve(int u, int p) {
    while (1) {
        int k = random(p);
        if (k == 0) continue;
        int a = 1ll * k * u % p, b = k;
        vector <int> ret;
        while (a > 0) {
            if (a >= b) {
                ret.push_back(0);
                a -= b;
            }
            else {
                ret.push_back(1);
                swap(a, b);
            }
            if (ret.size() > 100) break;
        }
        if (ret.size() <= 100) return ret;
    }
}

int p, u, v;

int main(void) {
    srand(time(NULL));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> u >> v >> p;
    vector <int> a1 = solve(u, p);
    vector <int> a2 = solve(v, p);
    reverse(a2.begin(), a2.end());
    cout << a1.size() + a2.size() << endl;
    for (auto x: a1) cout << (x ? 3 : 2) << ' ';
    for (auto x: a2) cout << (x ? 3 : 1) << ' ';
    cout << endl;
    return 0;
}