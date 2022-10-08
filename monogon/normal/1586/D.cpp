
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

int query(const vi &a) {
    cout << "?";
    for(int x : a) cout << " " << x;
    cout << endl;
    int k;
    cin >> k;
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n);
    vi p(n);
    int l = 1, r = 1;
    while(l < n) {
        a[n - 1] = 1;
        rep(i, 0, n - 1) a[i] = 1 + l;
        int k = query(a);
        if(k == 0) break;
        p[k - 1] = -l;
        l++;
    }
    while(r < n) {
        a[n - 1] = n;
        rep(i, 0, n - 1) a[i] = n - r;
        int k = query(a);
        if(k == 0) break;
        p[k - 1] = r;
        r++;
    }
    cout << "! ";
    for(int x : p) cout << x + l << ' ';
    cout << endl;
}