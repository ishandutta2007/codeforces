
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

bool check(ll n) {
    ll x = n;
    while(x > 0) {
        int dig = x % 10;
        x /= 10;
        if(dig != 0 && n % dig != 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        ll n;
        cin >> n;
        while(!check(n)) n++;
        cout << n << '\n';
    }
}