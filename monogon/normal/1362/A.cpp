
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
ll a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if(a < b) {
            swap(a, b);
        }
        if(a % b == 0) {
            rep(i, 0, 61) {
                if((1LL << i) == a / b) {
                    cout << (i + 2) / 3 << '\n';
                    goto lab;
                }
            }
            cout << "-1\n";
        }else {
            cout << "-1\n";
        }
        lab:;
    }
}