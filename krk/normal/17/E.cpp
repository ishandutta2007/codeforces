#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2000005;
const int mod = 51123987;

char s[Maxn];
int n;
int st[Maxn], en[Maxn];
int res;

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    for (int i = 0; i < n; i++) {
        int f = d1[i] - 1;
        st[i - f]++; st[i + 1]--;
        en[i + 1]++; en[i + f + 2]--;
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    for (int i = 0; i + 1 < n; i++) if (d2[i + 1] > 0) {
        int f = d2[i + 1] - 1;
        st[i - f]++; st[i + 1]--;
        en[i + 2]++; en[i + 1 + f + 2]--;
    }
    int curst = 0, curen = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        curst += st[i];
        curen += en[i];
        res = (res + ll(curst) * (curst - 1) / 2 % mod) % mod;
        cur = (cur - curen % mod + mod) % mod;
        res = (res + ll(cur) * curst) % mod;
        cur = (cur + curst) % mod;
    }
    cout << res << endl;
    return 0;
}