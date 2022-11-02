#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
ll c3(ll n) {
    return n * (n - 1) * (n - 2) / 6;
}

ll c2(ll n) {
    return n * (n - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    auto it = cnt.begin();
    if (it->second >= 3) {
        cout << c3(it->second) << endl;
        return 0;
    }
    auto s = it;
    s++;
    if (it->second == 2) {
        cout << c2(it->second) * s->second << endl;
        return 0;
    }
    it++;
    if (it->second >= 2) {
        cout << c2(it->second) << endl;
        return 0;
    }
    it++;
    cout << it->second << endl;
}