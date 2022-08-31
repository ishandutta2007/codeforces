#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

int m[max_n];
int n, d;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        memset(m, 0, sizeof(m));
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (m[i] == 0) {
                continue;
            }
            if (i > d) {
                break;
            }
            --m[i];
            d -= i;
            ++ans;
            --i;
        }
        cout << ans << endl;
    }

    return 0;
}