
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int cnt = s.length() + t.length();
    while(!s.empty() && !t.empty() && s.back() == t.back()) {
        s.pop_back();
        t.pop_back();
        cnt -= 2;
    }
    cout << cnt << '\n';
}