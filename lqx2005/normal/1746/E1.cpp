#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define ROF(i, r, l) for(int i = (r); i >= (l); i--)
#define ll long long
#define vi vector<int>
using namespace std;
const int N = 2e5 + 10;
int ask(vi a) {
    cout << "? ";
    cout << sz(a) << " ";
    for(auto x : a) cout << x <<" ";
    cout << endl;
    string res;
    cin >> res;
    return res == "YES";
}
int guess(int x) {
    cout << "! " << x << endl;
    string res;
    cin >> res;
    return res == ":)";
}
void solve(vi a) {
    if(sz(a) == 2) {
        if(guess(a[0]));
        else guess(a[1]);
        return;
    }
    vi g[3];
    FOR(j, 0, sz(a) - 1) {
        g[j % 3].emplace_back(a[j]);
    }
    int a1 = ask(g[2]);
    if(!a1) {
        int a2 = ask(g[2]);
        if(a1 == a2) {
            vi to = g[0];
            to.insert(to.end(), g[1].begin(), g[1].end());
            solve(to);
            return;
        } else {
            a1 = a2;
        }
    }
    int a2 = ask(g[0]);
    vi to = g[2];
    if(a1 != a2) {
        to.insert(to.end(), g[1].begin(), g[1].end());
    } else {
        to.insert(to.end(), g[0].begin(), g[0].end());
    }
    solve(to);
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if(n == 1) {
        guess(1);
        return 0;
    }
    vi a(n);
    FOR(i, 0, n - 1) a[i] = i + 1;
    solve(a);
}