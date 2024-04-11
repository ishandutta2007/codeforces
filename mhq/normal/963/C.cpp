#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)1e18;
map < ll, int > fi;
map < ll, int > se;
map < pair < ll, ll >, ll > all;
int n;
ll mult(ll a, ll b) {
    if (a > INF / b) {
        cout << 0;
        exit(0);
    }
    return a * b;
}
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return a + b;
}
ll lcm(ll a, ll b) {
    ll aa = a / gcd(a, b);
    return mult(aa, b);
}
ll divisors(ll A) {
    assert(A <= (1e13));
    ll ans = 0;
    for (int i = 1; 1LL * i * i <= A; i++) {
        if ((A % i) == 0) {
            if (i != (A / i)) ans += 2;
            else ans += 1;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
   // freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll w, h, c;
        cin >> w >> h >> c;
        all[make_pair(w, h)] = c;
        fi[w]++;
        se[h]++;
    }
    vector < ll > fic, sec;
    for (auto it = fi.begin(); it != fi.end(); it++) {
        fic.push_back((*it).first);
    }
    for (auto it = se.begin(); it != se.end(); it++) {
        sec.push_back((*it).first);
    }
    int fiz = fic.size();
    int sez = sec.size();
    if (1LL * fiz * sez != n) {
        cout << 0;
        return 0;
    }
    vector < vector < ll > > matrix;
    matrix.resize(fiz, vector < ll > (sez, 0));
    for (int i = 0; i < fic.size(); i++) {
        for (int j = 0; j < sec.size(); j++) {
            ll val = all[make_pair(fic[i], sec[j])];
            if (val == 0) {
                cout << 0;
                return 0;
            }
            matrix[i][j] = val;
        }
    }
    ll curA = matrix[0][0];
    for (int i = 0; i < sez; i++) {
        curA = gcd(curA, matrix[0][i]);
    }
    ll curB = 1;
    for (int i = 0; i < fiz; i++) {
        curB = lcm(curB, matrix[0][0] / gcd(matrix[i][0], matrix[0][0]));
    }
    if (curA % curB != 0) {
        cout << 0;
        return 0;
    }
    vector < ll > sampF(fiz);
    vector < ll > sampS(sez);
    ll x = curB;
    for (int i = 0; i < fiz; i++) {
        ll d = gcd(matrix[i][0], matrix[0][0]);
        sampF[i] = mult((x / (matrix[0][0] / d)), matrix[i][0] / d);
    }
    for (int i = 0; i < sez; i++) {
        sampS[i] = (matrix[0][i] / x);
    }
    for (int i = 0; i < fiz; i++) {
        for (int j = 0; j < sez; j++) {
            if (mult(sampF[i], sampS[j]) != matrix[i][j]) {
                cout << 0;
                return 0;
            }
        }
    }
    cout << divisors(curA / curB);
    return 0;
}