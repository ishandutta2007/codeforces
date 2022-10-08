
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define pt complex<ll>
#define x real()
#define y imag()
#define dot(u, v) (conj(u) * (v)).x
#define cross(u, v) (conj(u) * (v)).y

const pt I(0, 1);
bool flag = false;

istream &operator>>(istream &is, pt &p) {
    ll X, Y;
    is >> X >> Y;
    p = {X, Y};
    return is;
}

vector<pt> upperhull(const vector<pt> &v) {
    vector<pt> u;
    int m;
    for(pt p : v) {
        while((m = u.size()) > 1) {
            pt q = u[m - 1], r = u[m - 2];
            if(cross(q - r, p - q) >= 0) break;
            u.pop_back();
        }
        u.push_back(p);
    }
    return u;
}
vector<pt> hull(vector<pt> &v) {
    vector<pt> u = upperhull(v);
    reverse(v.begin(), v.end());
    vector<pt> l = upperhull(v);
    for(int i = 1; i + 1 < l.size(); i++) {
        u.push_back(l[i]);
    }
    return u;
}

int n, m;
pt p;
vector<pt> a, b;

bool cmp(const pt &p, const pt &q) {
    return pair(p.x, p.y) < pair(q.x, q.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p;
        a.push_back(p);
    }
    cin >> m;
    b = vector<pt>(a.begin(), a.end());
    for(int i = 0; i < m; i++) {
        cin >> p;
        b.push_back(p);
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    b = hull(b);
    sort(b.begin(), b.end(), cmp);
    
    cout << (a == b ? "YES" : "NO") << endl;
}