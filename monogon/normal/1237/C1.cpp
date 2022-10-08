
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

vector<pt> v;
int n;
pt p;
const int N = 2005;
bool rem[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
    }
    for(int i = 0; i < n; i++) {
        if(rem[i]) continue;
        int minj = i + 1;
        ll mindist = 1e10;
        for(int j = i + 1; j < n; j++) {
            if(rem[j]) continue;
            ll d = dist(v[i], v[j]);
            if(d < mindist) {
                mindist = d;
                minj = j;
            }
        }
        cout << (i + 1) << " " << (minj + 1) << endl;
        rem[minj] = true;
    }
}