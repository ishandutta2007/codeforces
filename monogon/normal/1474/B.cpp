
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

bool prime(ll x) {
    if(x == 1) return false;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int d;
        cin >> d;
        ll val = d + 1;
        while(!prime(val)) val++;
        ll val2 = val + d;
        while(!prime(val2)) val2++;
        cout << val * val2 << '\n';
    }
}