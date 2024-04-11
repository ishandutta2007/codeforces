
#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 211, inf = 1000111222;
int n;
int m[max_n];
int o[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    int ans = 0;

    for (int i = 0; i < n; i += 2) {
        int pj = -1;
        for (int j = i + 1; j < n; ++j) {
            if (m[j] == m[i]) {
                pj = j;
                break;
            }
        }
        ans += (pj - i - 1);
        for (int j = pj; j > i; --j) {
            m[j] = m[j - 1];
        }
    }
    cout << ans;
    return 0;
}