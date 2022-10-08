
#include <bits/stdc++.h>

#define ll long long
using namespace std;

typedef tuple<ll, ll, ll> pt;
#define x(t) get<0>(t)
#define y(t) get<1>(t)
#define z(t) get<2>(t)
istream &operator>>(istream &is, pt &p) {
    ll X, Y, Z;
    is >> X >> Y >> Z;
    p = pt(X, Y, Z);
    return is;
}
ll dist(const pt &a, const pt &b) {
    return abs(x(a) - x(b)) + abs(y(a) - y(b)) + abs(z(a) - z(b));
}

vector<pair<pt, int>> v;
int n;
pt p;
const int N = 2005;
bool rem[N];

bool cmpx(const pair<pt, int> &a, const pair<pt, int> &b) {
    pt p1 = a.first, p2 = b.first;
    return x(p1) == x(p2) ? y(p1) == y(p2) ? z(p1) < z(p2) : y(p1) < y(p2) : x(p1) < x(p2);
}
// bool cmpy(const pair<pt, int> &a, const pair<pt, int> &b) {
//     pt p1 = a.first, p2 = b.first;
//     return y(p1) == y(p2) ? x(p1) == x(p2) ? z(p1) < z(p2) : x(p1) < x(p2) : y(p1) < y(p2);
// }
// bool cmpz(const pair<pt, int> &a, const pair<pt, int> &b) {
//     pt p1 = a.first, p2 = b.first;
//     return z(p1) == z(p2) ? y(p1) == y(p2) ? x(p1) < x(p2) : y(p1) < y(p2) : z(p1) < z(p2);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p;
        v.push_back({p, i + 1});
    }
    sort(v.begin(), v.end(), cmpx);
    vector<pair<pt, int>> v2;
    int i = 0;
    for(i = 0; i < n - 1; i++) {
        if(x(v[i].first) == x(v[i + 1].first) && y(v[i].first) == y(v[i + 1].first)) {
            cout << v[i].second << " " << v[i + 1].second << endl;
            i++;
        }else {
            v2.push_back(v[i]);
        }
    }
    if(i == n - 1) {
        v2.push_back(v[n - 1]);
    }
    v.clear();
    n = v2.size();
    for(i = 0; i < n - 1; i++) {
        if(x(v2[i].first) == x(v2[i + 1].first)) {
            cout << v2[i].second << " " << v2[i + 1].second << endl;
            i++;
        }else {
            v.push_back(v2[i]);
        }
    }
    if(i == n - 1) {
        v.push_back(v2[n - 1]);
    }
    n = v.size();
    for(int i = 0; i < n - 1; i += 2) {
        cout << v[i].second << " " << v[i + 1].second << endl;
    }
}