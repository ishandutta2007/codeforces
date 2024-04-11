#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> b(n);
    vector<ll> w(n);
    for (int i = 0; i < n; i++)
        cin >> b[i] >> w[i];
    vector<pll> other;
    for (int i = 1; i < n; i++)
        other.push_back(pll(b[i], w[i] + 1 - b[i]));
    sort(other.begin(), other.end());
    reverse(other.begin(), other.end());
    multiset<ll> better;
    int ptr = 0;
    int res = n;
    for (;;) {
        while (ptr < other.size() && other[ptr].first > b[0]) {
            better.insert(other[ptr].second);
            ptr++;
        }
        res = min(res, (int) better.size());
        if (better.size() == 0)
            break;
        auto it = better.begin();
        if (*it > b[0]) 
            break;
        b[0] -= *it;
        better.erase(it);
    }
    cout << res + 1 << endl;
    return 0;
}