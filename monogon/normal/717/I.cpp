
#pragma GCC optimize ("Ofast")
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

typedef double ftype;

struct pt3 {
    ftype x, y, z;
    pt3(ftype x = 0, ftype y = 0, ftype z = 0) : x(x), y(y), z(z) {}
    pt3 operator-(const pt3 &o) const {
        return pt3(x - o.x, y - o.y, z - o.z);
    }
    pt3 operator+(const pt3 &o) const {
        return pt3(x + o.x, y + o.y, z + o.z);
    }
    pt3 operator*(const ftype &f) const {
        return pt3(x * f, y * f, z * f);
    }
    pt3 cross(const pt3 &o) const {
        return pt3(y * o.z - z * o.y, z * o.x - x * o.z, x * o.y - y * o.x);
    }
    ftype dot(const pt3 &o) const {
        return x * o.x + y * o.y + z * o.z;
    }
    ftype len() const {
        return hypot(x, hypot(y, z));
    }
};

const int N = 1e5 + 5;
int n, m;
pt3 p[N], q[N];

int sgn(ftype f) {
    if(abs(f) < 0.5) return 0;
    if(f > 0) return 1;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        int x, y, z;
        cin >> x >> y >> z;
        p[i].x = x;
        p[i].y = y;
        p[i].z = z;
    }
    cin >> m;
    rep(i, 0, m) cin >> q[i].x >> q[i].y >> q[i].z;
    pt3 a = (p[1] - p[0]).cross(p[2] - p[0]);
    pt3 b = (q[1] - q[0]).cross(q[2] - q[0]);
    pt3 u = a.cross(b);
    if((a.cross(b)).len() < 0.5) {
        cout << "NO\n";
        return 0;
    }
    vector<pair<ftype, int>> ve;
    vi signs1(n, 0), signs2(m, 0);
    rep(i, 0, n) signs1[i] = sgn((p[i] - q[0]).dot(b));
    rep(i, 0, m) signs2[i] = sgn((q[i] - p[0]).dot(a));
    int k = 2;
    rep(i, 0, n) {
        int j = (i + 1) % n;
        int s1 = signs1[i];
        int s2 = signs1[j];
        while(k != i && (k == j || signs1[k] == 0)) k = (k + 1) % n;
        if(s1 != 0 && s1 != s2 && (s2 != 0 || s1 != signs1[k])) {
            ftype t = b.dot(p[i] - q[0]) / b.dot(p[i] - p[j]);
            pt3 P = p[i] + (p[j] - p[i]) * t;
            ve.emplace_back(P.dot(u), s1);
        }
    }
    k = 2;
    rep(i, 0, m) {
        int j = (i + 1) % m;
        int s1 = signs2[i];
        int s2 = signs2[j];
        while(k != i && (k == j || signs2[k] == 0)) k = (k + 1) % m;
        if(s1 != 0 && s1 != s2 && (s2 != 0 || s1 != signs2[k])) {
            ftype t = a.dot(q[i] - p[0]) / a.dot(q[i] - q[j]);
            pt3 Q = q[i] + (q[j] - q[i]) * t;
            ve.emplace_back(Q.dot(u), 0);
        }
    }
    bool in = false;
    sort(all(ve));
    int ans = 0;
    for(auto &pa : ve) {
        int ty = pa.second;
        if(ty == 0) {
            in = !in;
        }else if(in) {
            ans += ty;
        }
    }
    cout << (ans == 0 ? "NO" : "YES") << '\n';
}