#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxb = 60;
const int Maxn = 1005;

int T;
int n, m;
ll a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            a[i] = 0;
            string s; cin >> s;
            for (int j = 0; j < s.length(); j++)
                if (s[j] == '1') a[i] |= 1ll << ll(int(s.length()) - 1 - j);
        }
        ll lef = 0, rig = (1ll << ll(m)) - 1ll;
        ll nd = ((1ll << ll(m)) - n + 1) / 2;
        while (lef <= rig) {
            ll mid = lef + rig >> 1;
            ll my = mid + 1ll;
            for (int i = 0; i < n; i++)
                if (a[i] <= mid) my--;
            if (my >= nd) rig = mid - 1ll;
            else lef = mid + 1ll;
        }
        rig++;
        for (int i = m - 1; i >= 0; i--)
            printf("%d", bool(rig & 1ll << ll(i)));
        printf("\n");
    }
    return 0;
}