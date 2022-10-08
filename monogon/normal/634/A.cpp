
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

const int N = 2e5 + 5;
int n, a, b;
int kmp[3 * N];

void makekmp(const vi &ve) {
    int n = sz(ve);
    int i = 1, j = 0;
    while(i < n) {
        if(ve[i] == ve[j]) kmp[i++] = ++j;
        else if(j == 0) kmp[i++] = 0;
        else j = kmp[j - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vi va, vb;
    rep(i, 0, n) {
        cin >> a;
        if(a != 0) va.push_back(a);
    }
    int s = sz(va);
    rep(i, 0, n) {
        cin >> b;
        if(b != 0) vb.push_back(b);
    }
    if(sz(vb) != s) {
        cout << "NO\n";
        return 0;
    }
    va.push_back(-1);
    va.insert(va.end(), vb.begin(), vb.end());
    va.insert(va.end(), vb.begin(), vb.end());
    makekmp(va);
    rep(i, 0, sz(va)) {
        if(kmp[i] == s) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}