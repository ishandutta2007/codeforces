
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

// 0: 1
// 1: 4
// 2: 4
// 3: 12
// 4: 9

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n % 2 == 0) {
        cout << (n / 2 + 1) * (n / 2 + 1) << '\n';
    }else {
        cout << 4 * (n / 2 + 1) + 2 * (n / 2 + 1) * (n / 2) << '\n';
    }
}