
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
    int n;
    string s;
    cin >> n >> s;
    int d = 0, k = 0;
    map<pii, int> ma;
    for(char c : s) {
        if(c == 'D') d++;
        else k++;
        int g = gcd(d, k);
        int a = d / g, b = k / g;
        ma[{a, b}]++;
        cout << ma[{a, b}] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}