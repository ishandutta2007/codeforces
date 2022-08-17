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
    int n;
    string a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    ll ans = 0;
    if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
        ++ans;
    }
    for (int i = 0; i < n / 2; ++i) {
        int j = n - i - 1;
        if (b[i] == b[j]) {
            if (a[i] != a[j]) {
                ans++;
            }
        } else {
            set<char> s;
            s.insert(a[i]);
            s.insert(a[j]);
            int cnt = 0;
            if (s.count(b[i])) cnt++;
            if (s.count(b[j])) cnt++;
            ans += 2 - cnt;
            //cout << cnt << endl;
        }
    }
    cout << ans;
    return 0;
}