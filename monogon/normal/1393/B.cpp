
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// this has to be the worst problem I have ever witnessed in my life

int n;
map<int, int> ma;
multiset<int> ms;

void add(int x, int d) {
    if(ma[x] > 0) ms.erase(ms.find(ma[x]));
    ma[x] += d;
    ms.insert(ma[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int a;
    rep(i, 0, n) {
        cin >> a;
        add(a, 1);
    }
    // cout << (odd == 0 ? "YES" : "NO") << '\n';
    int q;
    cin >> q;
    while(q--) {
        char ch;
        cin >> ch >> a;
        add(a, (ch == '+' ? 1 : -1));
        int mx = (ms.empty() ? 0 : *prev(ms.end()));
        int mx2 = (ms.size() <= 1 ? 0 : *prev(prev(ms.end())));
        int mx3 = (ms.size() <= 2 ? 0 : *prev(prev(prev(ms.end()))));
        // int mx4 = (ms.size() <= 3 ? 0 : *prev(prev(prev(prev(ms.end())))));
        if(mx >= 8 || (mx >= 6 && mx2 >= 2) || (mx >= 4 && mx2 >= 4) || (mx >= 4 && mx2 >= 2 && mx3 >= 2)) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}