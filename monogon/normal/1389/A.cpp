
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
        int l, r;
        cin >> l >> r;
        if(r % 2 == 1) r--;
        if(l > r / 2) {
            cout << "-1 -1\n";
        }else {
            cout << r/2 << ' ' << r << '\n';
        }
    }
}