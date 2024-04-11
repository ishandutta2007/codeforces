#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<ll> v;

int main()
{
    //freopen("input.txt", "r", stdin);
    multiset<ll> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.PB(a);
        s.insert(a);
    }
    ll del = 0;
    for (int i = 0; i < n; ++i) {
        s.erase(s.find(v[i]));
        bool f = 0;
        for (ll pow2 = 2; pow2 <= 6e9; pow2 *= 2) {
            ll other = pow2 - v[i];
            if (s.find(other) != s.end()) {
                f = 1;
                break;
            }
        }
        if (f == 1) {
            s.insert(v[i]);
        } else {
            ++del;
        }
    }
    cout << del;
    return 0;
}