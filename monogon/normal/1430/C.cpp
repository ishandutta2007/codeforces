
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
        cout << 2 << '\n';
        if(n == 2) {
            cout << 1 << ' ' << 2 << '\n';
        }else if(n >= 3) {
            cout << n << ' ' << n - 2 << '\n';
            cout << n - 1 << ' ' << n - 1 << '\n';
            n--;
            while(n > 2) {
                cout << n << ' ' << n - 2 << '\n';
                n--;
            }
        }
    }
}