
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n;
ll X1[N], Y1[N], X2[N], Y2[N];
bool b[N];

bool sweep() {
    fill(b, b + n, false);
    multiset<ll> up, down;
    vector<pair<ll, int>> v;
    for(int i = 0; i < n; i++) {
        v.emplace_back(X1[i], i);
        v.emplace_back(X2[i], i + n);
    }
    sort(v.begin(), v.end());
    for(auto p : v) {
        int i = p.second % n;
        b[i] = !b[i];
        if(b[i]) {
            up.insert(Y2[i]);
            down.insert(Y1[i]);
        }else {
            up.erase(up.find(Y2[i]));
            down.erase(down.find(Y1[i]));
        }
        if(up.size() && *up.begin() < *prev(down.end())) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> X1[i] >> X2[i] >> Y1[i] >> Y2[i];
    }
    if(sweep()) {
        cout << "NO" << endl;
        return 0;
    }
    swap(X1, Y1);
    swap(X2, Y2);
    cout << (sweep() ? "NO" : "YES") << endl;
}