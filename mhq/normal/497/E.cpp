#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
ll n;
int k;
vector < vector < int > > matrix_mult(vector < vector < int > > a, vector < vector < int > > b) {
    vector < vector < int > > c(k + 1, vector < int >(k + 1, 0));
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            for (int t = 0; t <= k; t++) {
                c[i][t] = sum(c[i][t], mult(a[i][j], b[j][t]));
            }
        }
    }
    return c;
}
vector < vector < int > > pref[100];
vector < vector < int > > shift_by_1(vector < vector < int > > mat) {
    vector < vector < int > > c(k + 1, vector < int >(k + 1, 0));
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int ni = i;
            if (ni < k) ni = (ni + k - 1) % k;
            int nj = j;
            if (nj < k) nj = (nj + k - 1) % k;
            c[i][j] = mat[ni][nj];
        }
    }
    return c;
}
void print(vector < vector < int > >& c) {
    for (auto t : c) {
        for (int v : t) cout << v << " ";
        cout << '\n';
    }
    cout << "------------" << endl;
}
void init() {
    ll digs = 0;
    ll cop = n;
    while (cop > 0) {
        cop /= k;
        digs++;
    }
    pref[0].resize(k + 1, vector < int >(k + 1, 0));
    for (int i = 1; i < k; i++) {
        pref[0][i][i] = 1;
    }
    pref[0][0][k] = 1;
    pref[0][k][0] = mod - 1;
    pref[0][k][k] = 2;
   // print(pref[0]);
   // print(pref[0]);
    //auto t = shift_by_1(pref[0]);
  //  print(t);
    //print(shift_by_1(pref[0]));
    for (int step = 0; step < digs; step++) {
        pref[step + 1] = pref[step];
        auto cur = pref[step];
        //if (step == 0) print(cur);
        for (int i = 1; i <= k - 1; i++) {
            cur = shift_by_1(cur);
            //if (step == 0) print(cur);
            pref[step + 1] = matrix_mult(pref[step + 1], cur);
        }
    }
    // digs =
}
vector < vector < int > > solve(ll n) {
    //cout << n << endl;
    if (n == 0) {
        vector < vector < int > > c(k + 1, vector < int >(k + 1, 0));
        for (int i = 0; i <= k; i++) {
            c[i][i] = 1;
        }
        return c;
    }
    ll dig = 0;
    ll pw = 1;
    while (pw <= n / k) {
        pw *= k;
        dig++;
    }
    if (n == pw) return pref[dig];
    ll steps = n / pw;
    ll left = n - steps * pw;
    auto cur_mat = solve(0);
    auto cur_coef = pref[dig];
    for (int i = 0; i < steps; i++) {
        cur_mat = matrix_mult(cur_mat, cur_coef);
        cur_coef = shift_by_1(cur_coef);
    }
    auto other_mat = solve(left);
    for (int i = 0; i < steps; i++) {
        other_mat = shift_by_1(other_mat);
    }
    //print(cur_mat);
   // print(other_mat);
    return matrix_mult(cur_mat, other_mat);
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    cin >> n >> k;
    init();
    auto mat = solve(n);
    cout << mat[k][k];
    return 0;
}