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

int m[max_n];
int s[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        s[i] = m[i];
        if (i + 2 < n) {
            s[i] += s[i + 2];
        }
    }
    int ans = 0;
    int sc = 0, sn = 0;
    for (int  i = 0; i < n; ++i) {
        int cc = sc;
        int cn = sn;
        if (i % 2 == 0) {
            cc += s[i + 1];
            cn += s[i + 2];
            sc +=  m[i];
        } else {
            cn += s[i + 1];
            cc += s[i + 2];
            sn += m[i];
        }
        if (cn == cc) {
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}