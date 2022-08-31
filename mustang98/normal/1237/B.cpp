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

int a[max_n];
int b[max_n];
int p[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> b[j];
    }
    for (int i = 0; i < n; ++i) {
        p[a[i]] = i;
    }
    for (int i = 0; i  <n; ++i) {
        b[i] = p[b[i]];
    }
    int ans = 0;
    int mn = b[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        if (mn < b[i]) {
            ++ans;
        }
        mn = min(mn, b[i]);
    }
    cout << ans << endl;
    return 0;
}