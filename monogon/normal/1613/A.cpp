
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

void solve() {
    string x, x2;
    int p, p2;
    cin >> x >> p >> x2 >> p2;
    char ans = '>';
    if(x.length() + p == x2.length() + p2) {
        while(x.length() < x2.length()) x.push_back('0');
        while(x2.length() < x.length()) x2.push_back('0');
        if(x < x2) ans = '<';
        else if(x == x2) ans = '=';
    }else if(x.length() + p < x2.length() + p2) {
        ans = '<';
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}