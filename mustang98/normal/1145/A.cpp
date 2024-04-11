#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

vector<int> v;
int ans = 1;

bool is_sor(vector<int> v) {
    for (int i = 0; i + 1 < v.size(); ++i) {
        if (v[i] > v[i + 1]) return false;
    }
    return true;
}

void solve(vector<int> v) {
    if (is_sor(v)) {
        ans = max(ans, int(v.size()));
        return;
    }
    int h = v.size() / 2;
    vector<int> l, r;
    for (int i = 0; i < h; ++i) {
        l.PB(v[i]);
    }
    for (int i = h; i < v.size(); ++i) {
        r.PB(v[i]);
    }
    solve(l);
    solve(r);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.PB(a);
    }
    solve(v);
    cout << ans << endl;

    return 0;
}