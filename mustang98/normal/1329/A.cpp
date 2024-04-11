#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int n, m;
vector<int> v;
int ans[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    ll sum = 0;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        v.PB(a);
        sum += a;
        if (i + a > n) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (sum < n) {
        cout << -1 << endl;
        return 0;
    }
    ans[m] = n;
    for (int i = m - 1; i >= 0; --i) {
        ans[i] = min(ans[i + 1] - 1, n - v[i]);
    }
    ans[0] = 0;
    for (int i = 1; i < m; ++i) {
        if (ans[i] > ans[i - 1] + v[i - 1]) {
            ans[i] = ans[i - 1] + v[i - 1];
        } else {
            break;
        }
    }
    for (int i =0 ; i < m; ++i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;


    return 0;
}