
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define pt complex<ll>
#define x real()
#define y imag()
#define cross(u, v) (conj(u) * (v)).y

const int N = 2505;
int n;
ll X, Y;
pt p[N];
vector<pt> v;

bool upper(const pt &a) {
    return a.y > 0 || (a.y == 0 && a.x > 0);
}
bool cmp(const pt &a, const pt &b) {
    return upper(a) != upper(b) ? upper(a) : cross(a, b) > 0;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> X >> Y;
        p[i] = {X, Y};
    }
    ll cnt = 1LL * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
    for(int k = 0; k < n; k++) {
        v.clear();
        for(int j = 0; j < n; j++)
            if(k != j) v.push_back(p[j] - p[k]);
        sort(v.begin(), v.end(), cmp);
        for(int i = 0, j = 1; i < n - 1; i++) {
            while(cross(v[i], v[j]) > 0) j = (j + 1) % (n - 1);
            ll amt = (i - j + n - 1) % (n - 1);
            cnt -= 1LL * amt * (amt - 1) * (amt - 2) / 6;
        }
    }
    cout << cnt << endl;
}