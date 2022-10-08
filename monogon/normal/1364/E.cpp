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

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    uniform_int_distribution<int> uni(l, r);
    return uni(mt);
}

const int N = 2050;
int n, mask[N];
// int perm[3] = {1, 0, 2};

int ask(int x, int y) {
    if(x == y) {
        return (1 << 12) - 1;
    }
    cout << "? " << x + 1 << ' '<< y + 1 << endl;
    // return perm[x] | perm[y];
    int ans = 0;
    cin >> ans;
    if(ans == -1) exit(0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    // subset of <= 19 numbers, ask all pairs
    int k = min(19, n);
    fill(mask, mask + n, (1 << 11) - 1);
    vi ve(n, 0);
    iota(all(ve), 0);
    shuffle(all(ve), mt);
    rep(i, 0, k) rep(j, i + 1, k) {
        int ans = ask(ve[i], ve[j]);
        mask[ve[i]] &= ans;
        mask[ve[j]] &= ans;
    }
    int ii = -1, jj = -1;
    rep(i, 0, k) rep(j, i + 1, k) {
        if((mask[ve[i]] & mask[ve[j]]) == 0) {
            ii = ve[i];
            jj = ve[j];
        }
    }
    while(ii == -1);
    // cout << "solving with: " << ii << ' ' << jj << endl;
    rep(i, 0, n) {
        if(i != ii && i != jj) {
            mask[i] = (ask(ii, i) & ask(jj, i));
        }
    }
    cout << "! ";
    rep(i, 0, n) {
        cout << mask[i] << ' ';
    }
    cout << '\n';
}