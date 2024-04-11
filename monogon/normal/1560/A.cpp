
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
    vi ve;
    for(int i = 1; sz(ve) < 1000; i++) {
        if(i % 3 != 0 && i % 10 != 3) ve.push_back(i);
    }
    int te;
    cin >> te;
    while(te--) {
        int k;
        cin >> k;
        cout << ve[k - 1] << '\n';
    }
}