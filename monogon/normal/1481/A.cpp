
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
    int px, py;
    string s;
    cin >> px >> py >> s;
    int minx = 0, maxx = 0, miny = 0, maxy = 0;
    for(char c : s) {
        maxx += (c == 'R');
        minx -= (c == 'L');
        maxy += (c == 'U');
        miny -= (c == 'D');
    }
    cout << (minx <= px && px <= maxx && miny <= py && py <= maxy ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}