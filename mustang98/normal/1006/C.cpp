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

ll m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    ll sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    multiset<ll> s;
    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        sum += m[i];
        s.insert(sum);
    }
    //cout << s.size() << endl;
    ll sum1 = 0;
    for (int i = 0; i < n; ++i) {
        s.erase(s.find(sum));
        sum -= m[i];
        sum1 += m[i];
        if (s.find(sum1) != s.end()) {
            ans = max(ans, sum1);
        }
    }
    cout << ans;
    return 0;
}