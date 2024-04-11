#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = (ll)1e9 + 7;
ll mult(ll a, ll b, ll mod) {
    return (a * b) % mod;
}
ll pw(ll a, ll b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1), mod);
    ll res = pw(a, b / 2);
    return mult(res, res, mod);
}
ll inv(ll a, ll b) {
    if (a == 0) return 0;
    if (a == 1) return 1;
    if (a >= b) return inv(a % b, b);
    return mult(b - inv(b % a, b), b / a, b);
}
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
void no() {
    cout << -1;
    exit(0);
}
const int maxN = 105;
int n, k;
int a[maxN], b[maxN], copa[maxN], copb[maxN];
vector < int > primes;
vector < int > valA[maxN];
vector < int > valB[maxN];
vector < bool > skip;
vector < int > nvalA[maxN], nvalB[maxN];
void go(int p) {
    for (int i = 1; i <= n; i++) {
        int exp = 0;
        while (a[i] % p == 0) {
            a[i] /= p;
            exp++;
        }
        valA[i].push_back(exp);
        exp = 0;
        while (b[i] % p == 0) {
            b[i] /= p;
            exp++;
        }
        valB[i].push_back(exp);
    }
}
void can(int ind, ll t) {
    vector < ll > vals;
    vals.resize(k);
    for (int i = 0; i < k; i++) {
        vals[i] = t * valB[ind][i] + valA[ind][i];
    }
    for (int i = 1; i <= n; i++) {
        int t = -1;
        for (int j = 0; j < k; j++) {
            if (t != -1) {
                if (valA[i][j] + t * valB[i][j] != vals[j]) no();
            }
            else {
                if (valB[i][j] == 0) {
                    if (valA[i][j] != vals[j]) no();
                }
                else {
                    if (valA[i][j] > vals[j]) no();
                    if ((vals[j] - valA[i][j]) % valB[i][j] != 0) no();
                    t = (vals[j] - valA[i][j]) / valB[i][j];
                }
            }
        }
    }
    cout << mult(copa[ind], pw(copb[ind], t), mod);
    exit(0);
}
pair < ll, ll > unite(pair < ll, ll > a, pair < ll, ll > b) {
    ll a1 = a.first;
    ll a2 = b.first;
    ll b1 = a.second;
    ll b2 = b.second;
    ll dif = a2 - a1;
    ll cop = b1;
    dif = (dif % b2 + b2) % b2;
    ll d = gcd(b1, b2);
    if (dif % d != 0) {
        no();
    }
    b1 /= d;
    dif /= d;
    b2 /= d;
    ll x = mult(dif, inv(b1, b2), b2);
    ll nx = x * cop + a1;
    return make_pair(nx, cop * b2);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        copa[i] = a[i];
        copb[i] = b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; 1LL * j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                go(j);
            }
        }
        if (a[i] > 1) go(a[i]);
        for (int j = 2; 1LL * j * j <= b[i]; j++) {
            if (b[i] % j == 0) {
                go(j);
            }
        }
        if (b[i] > 1) go(b[i]);
    }
    k = valA[1].size();
    skip.resize(k, false);
    for (int i = 0; i < k; i++) {
        int zero = -1;
        int nonzero = -1;
        for (int j = 1; j <= n; j++) {
            if (valB[j][i] == 0) zero = j;
            if (valB[j][i] != 0) nonzero = j;
        }
        if (nonzero == -1) {
            for (int j = 1; j <= n; j++) {
                if (valA[j][i] != valA[1][i]) no();
            }
            skip[i] = true;
        }
        else if (zero != -1) {
            int finalval = valA[zero][i];
            finalval -= valA[nonzero][i];
            if (finalval < 0) no();
            if (finalval % valB[nonzero][i] != 0) no();
            int t = finalval / valB[nonzero][i];
            can(nonzero, t);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (skip[j]) continue;
            nvalA[i].push_back(valA[i][j]);
            nvalB[i].push_back(valB[i][j]);
        }
        valA[i] = nvalA[i];
        valB[i] = nvalB[i];
    }
    if (valA[1].size() == 0) {
        cout << copa[1];
        exit(0);
    }
    k = valA[1].size();
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < k; j++) {
            if (valB[1][0] * valB[i][j] != valB[1][j] * valB[i][0]) {
                int det1 = -valB[1][0] * valB[i][j] + valB[1][j] * valB[i][0];
                int det2 = +(valA[i][j] - valA[1][j]) * valB[i][0] - valB[i][j] * (valA[i][0] - valA[1][0]); // for t1
                int det3 = +(valA[i][j] - valA[1][j]) * valB[1][0] - valB[1][j] *  (valA[i][0] - valA[1][0]); // for ti
                int t1 = det2 / det1;
                if (det1 * t1 != det2) no();
                if (t1 < 0) no();
                can(1, t1);
            }
            if ((valB[1][0] * (valA[i][j] - valA[1][j]) - valB[1][j] * (valA[i][0] - valA[1][0])) != 0) no();
        }
    }
    vector < pair < int, int > > conditions;
    ll limit = 0;
    for (int i = 2; i <= n; i++) {
        int x = valB[1][0];
        int y = valA[i][0] - valA[1][0];
        int mod = valB[i][0];
        if (y >= 0) {
            limit = max(limit, (ll)(y + x - 1) / x);
        }
        y = (y % mod + mod) % mod;
        int d = gcd(x, mod);
        if (y % d != 0) no();
        x /= d;
        mod /= d;
        y /= d;
        if (mod == 1) conditions.push_back(make_pair(0, 1));
        else {
            int val = mult(y, inv(x, mod), mod);
            conditions.push_back(make_pair(val, mod));
        }
    }
    if (conditions.size() == 0) {
        can(1, 0);
    }
    /*cout << "HERE" << endl;
    for (int i = 0; i < conditions.size(); i++) {
        cout << conditions[i].first << " " << conditions[i].second << endl;
    }*/
    pair < ll, ll > cur = make_pair((ll)conditions[0].first, (ll)conditions[0].second);
    for (int i = 1; i < conditions.size(); i++) {
        cur = unite(cur, conditions[i]);
    }
    //    cout << cur.first << " " << cur.second << endl;
    ll t = cur.first;
    if (cur.second == 1) t = limit;
    while (t < limit) t += cur.second;
    can(1, t);
}