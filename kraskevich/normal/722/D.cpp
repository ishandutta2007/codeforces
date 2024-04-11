#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int last(const set<int>& s) {
    auto it = s.end();  
    it--;
    return *it;
}

bool go(set<int>& s) {
    int y = last(s);
    int x = y;
    while (x > 1 && s.find(x) != s.end()) {
        x /= 2;
    } 
    if (s.find(x) != s.end())
        return false;
    s.insert(x);
    s.erase(y);
    return true;
}

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    while (go(s));
    for (int x : s)
        cout << x << " ";
    cout << endl;  
    return 0;
}