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

vector<ll> v[500];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i =0 ; i < n; ++i) {
        ll a;
        scanf("%I64d", &a);
        int c2 = 0;
        ll aa = a;
        while (aa % 2 == 0) {
            ++c2;
            aa /= 2;
        }
        v[c2].PB(a);
    }
    int mx = 0;
    for (int i = 0; i < 500; ++i) {
        if (v[i].size() > v[mx].size()) {
            mx = i;
        }
    }
    vector<ll> ans;
    for (int i = 0; i < 500; ++i) {
        if (i == mx) {
            continue;
        }
        for (ll a : v[i]) {
            ans.PB(a);
        }
    }
    cout << ans.size() << endl;
    for (ll a : ans) {
        printf("%I64d ", a);
    }
    return 0;
}