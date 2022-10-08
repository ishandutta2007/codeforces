
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

template<int m>
struct mod {
    long long x;
    mod() : x(0) {}
    mod(long long xx) : x(xx) {
        if(abs(x) >= m) x %= m;
        if(x < 0) x += m;
    }
    mod operator+(const mod &a) const {
        mod n;
        n.x = x + a.x;
        if(n.x >= m) n.x -= m;
        return n;
    }
    mod operator-(const mod &a) const {
        mod n;
        n.x = x - a.x;
        if(n.x < 0) n.x += m;
        return n;
    }
    mod operator*(const mod &a) const {
        return x * a.x;
    }
    mod operator+=(const mod &a) {
        x += a.x;
        if(x >= m) x -= m;
        return *this;
    }
    mod operator-=(const mod &a) {
        x -= a.x;
        if(x < 0) x += m;
        return *this;
    }
    mod operator*=(const mod &a) {
        x = (x * a.x) % m;
        return *this;
    }
    mod pow(long long b) const {
        mod ans = 1;
        mod a = *this;
        while(b > 0) {
            if(b & 1) ans *= a;
            a *= a;
            b /= 2;
        }
        return ans;
    }
    mod inv() const {
        return pow(m - 2);
    }
    mod operator/(const mod &a) const {
        return (*this) * a.inv();
    }
    mod operator/=(const mod &a) {
        return (*this) *= a.inv();
    }
    bool operator==(const mod &o) const {
        return x == o.x;
    }
    bool operator!=(const mod &o) const {
        return x != o.x;
    }
    long long operator()() const {
        return x;
    }
};

template<int m>
istream &operator>>(istream &is, mod<m> &n) {
    long long x;
    is >> x;
    n = x;
    return is;
}

const int M = 998244353;
using base = mod<M>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int p, s, r;
    cin >> p >> s >> r;
    int P = p + s + 5;
    vector<vector<base>> choose(P, vector<base>(P));
    rep(i, 0, P) {
        rep(j, 0, P) {
            if(j == 0) choose[i][j] = 1;
            else if(i == 0) choose[i][j] = 0;
            else choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
        }
    }

    base ans = 0;
    vector<base> f;
    rep(i, 1, p + 1) {
        for(int k = r; k * i <= s; k++) {
            base add = 0;
            int sum = s - i * k;
            int people = p - i;
            int mx = k - 1;
            if(people == 0) {
                if(sum == 0) add += 1;
            }else if(mx >= 0) {
                // f.clear();
                // for(int j = 0; mx * j <= sum && j <= people; j++) {
                //     f.push_back(choose[people][j] * choose[sum - mx * j + people - 1][people - 1]);
                // }
                // for(int j = sz(f) - 1; j >= 0; j--) {
                //     for(int l = j + 1; l < sz(f); l++) {
                //         f[j] -= choose[l][j] * f[l];
                //     }
                // }
                // add = f[0];
                for(int j = 0; (mx + 1) * j <= sum && j <= people; j++) {
                    base x = choose[people][j] * choose[sum - (mx + 1) * j + people - 1][people - 1];
                    if(j % 2 == 0) add += x;
                    else add -= x;
                }
            }
            ans += choose[p - 1][i - 1] * add / i;
        }
    }
    base tot = choose[s - r + p - 1][p - 1];
    ans /= tot;

    cout << ans() << '\n';
}