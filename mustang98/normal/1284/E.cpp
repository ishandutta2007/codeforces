#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2511, inf = 1000111222;

struct point {
    ll x, y;
    bool const operator < (const point &p) const {
    	if (y == 0)
    		return x < 0;
        return x * p.y - y * p.x > 0;
    }
};

ll vect(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

ll solve(vector<point> a, vector<point> b) {
    ll an = a.size();
    ll bn = b.size(), j = 0, j1 = 0;
    if (an == 0 || bn == 0)
        return 0ll;

    std::stable_sort(a.begin(), a.end());
    std::stable_sort(b.begin(), b.end());

    ll ans = 0;
    for (ll i = 0; i < an; i++)
    {
        while (j < bn && vect(a[i], b[j]) > 0) {
            j++;
            j1 = j;
        }
        while (j1 < bn && vect(a[i], b[j1]) == 0) {
            j1++;
        }
        ans += j * (bn - j1);
    }
	ll l = 0, r = bn - 1;
    while (l < bn && b[l].y == 0 && b[l].x < 0) {
        l++;
    }
    while (r >= 0 && b[r].y == 0 && b[r].x > 0) {
        r--;
    }
	ans -= l * (bn - 1LL - r) * an;
    return ans;
}

ll solve(const vector<point>& v) {
    int n = v.size();
    vector<point> up, down, OX;
    for (int i = 0; i < n; i++) {
        point p = v[i];
        if (p.y == 0) OX.PB(p);
        if (p.y > 0) up.PB(p);
        if (p.y < 0) down.PB(p);
    }

    ll ans = 0;
    for (point x : OX) down.PB(x);
    ans += solve(up, down);

    for (point x : OX) down.pop_back();
    ans += solve(down, up);
    return ans;
}

int main ()
{
    vector<point> v;
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<point> v1 = v;
        v1.erase(v1.begin() + i);
        for (int j = 0; j < v1.size(); ++j) {
            v1[j].x -= v[i].x;
            v1[j].y -= v[i].y;
        }
        ans += solve(v1);
    }
    cout << (ans * (n - 4)) / 2 << endl;
    return 0;
}