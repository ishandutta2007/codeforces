
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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int i = 0;
    while(s[i] != '*') i++;
    s[i] = 'x';
    int cnt = 0;
    cnt++;
    while(true) {
        int j = min(n - 1, i + k);
        while(j > i && s[j] == '.') j--;
        if(i == j) break;
        cnt++;
        s[j] = 'x';
        i = j;
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}