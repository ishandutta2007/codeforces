

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

// int mex(vi &ve) {
//     sort(all(ve));
//     ve.erase(unique(all(ve)), ve.end());
//     int i = 0;
//     while(i < sz(ve) && ve[i] == i) i++;
//     return i;
// }

// map<int, int> ma;

// int solve(int mask) {
//     if(ma.count(mask)) return ma[mask];
//     vi ve;
//     rep(i, 1, n + 1) {
//         if((mask >> (i - 1)) & 1) {
//             int mask2 = mask;
//             for(int j = i; j <= n; j += i) {
//                 if((mask2 >> (j - 1)) & 1) {
//                     mask2 ^= (1 << (j - 1));
//                 }
//             }
//             ve.push_back(solve(mask2));
//         }
//     }
//     return ma[mask] = mex(ve);
// }

int grundy[31] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12, 14};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    int cnt = 0;
    int gr = 0;
    set<ll> bad;
    for(ll i = 2; i * i <= n; i++) {
        if(bad.count(i)) continue;
        ll mul = 1;
        int p = 0;
        while(mul * i <= n) {
            mul *= i;
            bad.insert(mul);
            p++;
        }
        cnt += p;
        // cout << grundy[p] << ' ';
        gr ^= grundy[p];
    }
    // cout << endl;
    if((n - cnt) % 2 == 1) {
        gr ^= 1;
    }
    cout << (gr == 0 ? "Petya" : "Vasya") << '\n';
}