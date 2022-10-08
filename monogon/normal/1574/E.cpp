
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

template<int m>
ostream &operator<<(ostream &os, const mod<m> &n) {
    return os << n();
}

const int M = 998244353;
using base = mod<M>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    map<pii, int> ma;
    vector<vi> row(n + 1, vi(2, 0));
    vector<vi> col(m + 1, vi(2, 0));
    vi R(4, 0), C(4, 0);
    R[0] = n;
    C[0] = m;
    auto rem = [&](int i, int j) {
        if(ma.count({i, j}) == 0) return;
        int val = ma[{i, j}];
        R[(row[i][0] > 0) + 2 * (row[i][1] > 0)]--;
        row[i][val ^ (i % 2) ^ (j % 2)]--;
        R[(row[i][0] > 0) + 2 * (row[i][1] > 0)]++;
        C[(col[j][0] > 0) + 2 * (col[j][1] > 0)]--;
        col[j][val ^ (i % 2) ^ (j % 2)]--;
        C[(col[j][0] > 0) + 2 * (col[j][1] > 0)]++;
        ma.erase({i, j});
    };
    auto add = [&](int i, int j, int val) {
        ma[{i, j}] = val;
        R[(row[i][0] > 0) + 2 * (row[i][1] > 0)]--;
        row[i][val ^ (i % 2) ^ (j % 2)]++;
        R[(row[i][0] > 0) + 2 * (row[i][1] > 0)]++;
        C[(col[j][0] > 0) + 2 * (col[j][1] > 0)]--;
        col[j][val ^ (i % 2) ^ (j % 2)]++;
        C[(col[j][0] > 0) + 2 * (col[j][1] > 0)]++;
    };
    while(k--) {
        int x, y, t;
        cin >> x >> y >> t;
        rem(x, y);
        if(t == -1) {
            // clear
        }else if(t == 0) {
            // add 0
            add(x, y, 0);
        }else if(t == 1) {
            // add 1
            add(x, y, 1);
        }
        base ans = 0;
        if(R[3] == 0) ans += base(2).pow(R[0]);
        if(C[3] == 0) ans += base(2).pow(C[0]);
        if(R[3] == 0 && C[3] == 0 && R[1] == 0 && C[1] == 0) ans -= 1;
        if(R[3] == 0 && C[3] == 0 && R[2] == 0 && C[2] == 0) ans -= 1;
        cout << ans << '\n';
    }
}