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

string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    ll n, x, y;
    cin >> n >> x >> y;
    cin >> s;
    ll cnt0 = 0;
    if (s[0] == '0') cnt0++;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '0' && s[i - 1] == '1') {
            cnt0++;
        }
    }
    if (cnt0 == 0) {
        cout << 0;
        return 0;
    }
    ll ans1 = y * cnt0;
    ll ans2 = x * (cnt0 - 1) + y;
    cout << min(ans1, ans2);

    return 0;
}