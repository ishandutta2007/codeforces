
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

void solve() {
    ll n;
    cin >> n;
    int i = 1;
    int count = 0;
    while(i * i <= n) {
        count++;
        i++;
    }
    i = 1;
    // i * i * i = j * j
    while(i * i * i <= n) {
        int j = sqrt(i * i * i);
        if(j * j != i * i * i) {
            count ++;
        }
        i++;
    }
    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}