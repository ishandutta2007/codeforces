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

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        ll n, m;
        cin >> n >> m;
        ll cnt = n / m;
        set<int> was;
        ll cur = m;
        set<int> s;
        for (int i = 0; i < 20; ++i) {
            s.insert(cur % 10);
            cur += m;
        }
        ll sum = 0;
        for (int a : s) {
            sum += a;
        }
        ll ans = sum * (cnt / s.size());
        cnt %= s.size();
        cur = m;
        for (int i = 0; i < cnt; ++i) {
            ans += cur % 10;
            cur += m;
        }
        cout << ans << "\n";
    }


    return 0;
}