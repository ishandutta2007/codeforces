#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111;
bool m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int cnt = 0, ans = 0;
    int n, a;
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a;
        if (m[a] == 0) {
            m[a] = 1;
            cnt++;
        } else {
            m[a] = 0;
            cnt--;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}