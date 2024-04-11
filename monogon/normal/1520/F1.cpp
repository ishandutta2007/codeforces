
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

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t, k;
    cin >> n >> t >> k;
    int L = 1, R = n;
    while(L < R) {
        int m = (L + R) / 2;
        int x = ask(1, m);
        if(m - x < k) {
            L = m + 1;
        }else {
            R = m;
        }
    }
    cout << "! " << L << endl;
}