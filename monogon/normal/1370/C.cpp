
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int t;
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        bool win = true;
        if(n == 1) {
            win = false;
        }else if(n == 2) {
            win = true;
        }else {
            int pow2 = 0;
            while(n % 2 == 0) {
                n /= 2;
                pow2++;
            }
            if(n == 1) {
                win = false;
            }else if(pow2 != 1) {
                win = true;
            }else {
                win = false;
                for(ll i = 3; i * i <= n; i++) {
                    if(n % i == 0) {
                        win = true;
                    }
                }
            }
        }
        cout << (win ? "Ashishgup" : "FastestFinger") << '\n';
    }
}