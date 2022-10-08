
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

int brute(int n, int k) {
    int a = n - 1, b = 0;
    k--;
    while(k--) {
        a = (a + n - 1) % n;
        b = (b + 1) % n;
        if(a == b) b = (b + 1) % n;
    }
    return b;
}

ll solve(ll n, ll k) {
    k--;
    if(n % 2 == 0) {
        return (k % n) + 1;
    }else {
        ll big = k / ((n - 1) / 2);
        ll b = (big * ((n + 1) / 2)) % n;
        b += k % ((n - 1) / 2);
        b %= n;
        return b + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
}