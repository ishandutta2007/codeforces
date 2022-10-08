
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
        ll k, x;
        cin >> k >> x;
        ll L = 0, R = 2 * k - 1;
        while(L < R) {
            ll M = L + (R - L) / 2;
            ll emote = 0;
            if(M <= k) emote = M * (M + 1) / 2;
            else emote = k * (k + 1) / 2 + (k - 1) * k / 2 - (2 * k - 1 - M) * (2 * k - 1 - M + 1) / 2;
            if(emote < x) {
                L = M + 1;
            }else {
                R = M;
            }
        }
        cout << L << '\n';
    }
}