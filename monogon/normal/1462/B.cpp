
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
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool flag = false;
        rep(off, 0, 5) {
            string s2 = s.substr(0, off) + s.substr(n - 4 + off);
            flag |= (s2 == "2020");
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}