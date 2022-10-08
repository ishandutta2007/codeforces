
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

const int N = 1e5 + 5;
int p[N];

int ask(int i) {
    if(p[i] != 0) return p[i];
    cout << "? " << i << endl;
    int x;
    cin >> x;
    return p[i] = x;
}

void ans(int i) {
    cout << "! " << i << endl;
    exit(0);
}

void solve(int L, int R) {
    if(R - L < 20) {
        int best = L;
        rep(i, L, R + 1) {
            if(ask(i) < ask(best)) best = i;
        }
        ans(best);
    }else {
        int M = (L + R) / 2;
        if(ask(M) < ask(M + 1)) {
            solve(L, M + 1);
        }else {
            solve(M, R);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n == 1) {
        ans(1);
    }else if(ask(1) < ask(2)) {
        ans(1);
    }else if(ask(n - 1) > ask(n)) {
        ans(n);
    }else {
        solve(1, n);
    }
}