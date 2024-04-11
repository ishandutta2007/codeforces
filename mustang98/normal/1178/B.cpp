#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

char s[max_n];
int cl[max_n];
int cr[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%s", s);
    int n = strlen(s);
    cl[0] = 0;
    for (int i = 1; i < n; ++i) {
        cl[i] = cl[i - 1];
        if (s[i] == 'v' && s[i - 1] == 'v') {
            ++cl[i];
        }
    }
    cr[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        cr[i] = cr[i + 1];
        if (s[i] == 'v' && s[i + 1] == 'v') {
            ++cr[i];
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'o') {
            ans += 1LL * cl[i] * cr[i];
        }
    }
    cout << ans << endl;
    return 0;
}