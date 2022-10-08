
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
        ll x;
        cin >> n >> x;
        vi a(n);
        bool isx = false, allx = true;
        ll sum = 0;
        rep(i, 0, n) {
            cin >> a[i];
            sum += a[i];
            if(a[i] == x) {
                isx = true;
            }else {
                allx = false;
            }
        }
        if(allx) {
            cout << "0\n";
        }else if(isx || sum == x * n) {
            cout << "1\n";
        }else {
            cout << "2\n";
        }
    }
}