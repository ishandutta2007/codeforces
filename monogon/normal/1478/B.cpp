
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

const int K = 1005;

bool lucky(int x, int d) {
    while(x > 0) {
        if(x % 10 == d) return true;
        x /= 10;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int q, d;
        cin >> q >> d;
        bitset<K> b;
        b.set(0, true);
        rep(i, 1, K) {
            rep(j, 1, i + 1) {
                if(lucky(j, d) && b[i - j]) {
                    b.set(i, true);
                }
            }
        }
        while(q--) {
            int x;
            cin >> x;
            if(x >= K || b[x]) {
                cout << "YES\n";
            }else {
                cout << "NO\n";
            }
        }
    }
}