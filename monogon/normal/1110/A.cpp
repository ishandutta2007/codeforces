
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

const int N = 1e5 + 5;
ll b, k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> b >> k;
    int sum = 0;
    rep(i, 0, k) {
        cin >> a[i];
        sum = (sum + a[i]) % 2;
    }
    if(b % 2 == 0) {
        sum = a[k - 1];
    }
    cout << (sum % 2 == 0 ? "even" : "odd") << "\n";
}