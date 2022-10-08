
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, t, v, p;
vector<pair<ll, int>> k, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> v;
    k.emplace_back(0, 0);
    c.emplace_back(0, 0);
    for(int i = 0; i < n; i++) {
        cin >> t >> p;
        (t == 1 ? k : c).emplace_back(p, i + 1);
    }
    sort(k.rbegin(), prev(k.rend()));
    sort(c.rbegin(), prev(c.rend()));
    for(int i = 1; i < k.size(); i++) {
        k[i].first += k[i - 1].first;
    }
    for(int i = 1; i < c.size(); i++) {
        c[i].first += c[i - 1].first;
    }
    int besti = 0, bestj = 0;
    ll cap = 0;
    for(int i = 0; i < k.size() && i <= v; i++) {
        int j = min((v - i) / 2, (int) c.size() - 1);
        ll vol = k[i].first + c[j].first;
        if(vol > cap) {
            cap = vol;
            besti = i;
            bestj = j;
        }
    }
    cout << cap << endl;
    for(int i = 1; i <= besti; i++) {
        cout << k[i].second << " ";
    }
    for(int j = 1; j <= bestj; j++) {
        cout << c[j].second << " ";
    }
    cout << endl;
}