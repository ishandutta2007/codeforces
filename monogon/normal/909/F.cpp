
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

vi solve1(int n) {
    if(n == 0) return {};
    int i = 1;
    while((1 << (i + 1)) <= n) i++;
    int m = 1 << i;
    int amt = n - m + 1;
    vi a = solve1(n - amt * 2);
    rep(i, 0, 2 * amt) a.push_back(n - i);
    return a;
}

vi solve2(int n) {
    if(n == 6) return {3, 6, 1, 5, 4, 2};
    if(n == 10) return {9, 7, 6, 5, 4, 3, 2, 10, 1, 8};
    if(n % 2 == 1) {
        vi a = {5, 3, 1, 6, 7, 4, 2};
        rep(i, 8, n + 1) {
            a.push_back(i ^ 1);
        }
        return a;
    }else {
        vi a(n);
        vi b = solve2(n / 2);
        rep(i, 0, n / 2) {
            a[2 * i + 1] = 2 * b[i];
        }
        rep(i, 0, n / 2 - 1) {
            a[2 * i] = 2 * i + 3;
        }
        a[n - 2] = 1;
        return a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n % 2 == 0) {
        cout << "YES\n";
        vi a = solve1(n);
        for(int x : a) cout << x << ' ';
        cout << '\n';
    }else {
        cout << "NO\n";
    }

    if(n < 6 || __builtin_popcount(n) == 1) {
        cout << "NO\n";
    }else {
        cout << "YES\n";
        vi a = solve2(n);
        for(int x : a) cout << x << ' ';
        cout << '\n';
    }
}