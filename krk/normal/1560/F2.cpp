#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxd = 11;

ll pw[Maxd];
ll ones[Maxd];
int T;
int n, k;


int main()
{
    pw[0] = 1;
    ones[0] = 0;
    for (int i = 1; i < Maxd; i++) {
        pw[i] = 10ll * pw[i - 1];
        ones[i] = ones[i - 1] + pw[i - 1];
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        stringstream ss; ss << n;
        string s; ss >> s;
        set <char> S;
        ll pref = 0;
        int i = 0;
        while (i < s.length()) {
            S.insert(s[i]);
            pref = 10ll * pref + int(s[i] - '0');
            int rem = int(s.length()) - 1 - i;
            if (S.size() < k && pref * pw[rem] + 9 * ones[rem] ||
                S.size() == k && pref * pw[rem] + int(*S.rbegin() - '0') * ones[rem] >= n) i++;
            else break;
        }
        if (i >= s.length()) { printf("%d\n", n); continue; }
        S.clear();
        pref = 0;
        for (int j = 0; j < i; j++) {
            S.insert(s[j]);
            pref = 10ll * pref + int(s[j] - '0');
        }
        for (char d = s[i] + 1; d <= '9'; d++) if (S.size() + !S.count(d) <= k) {
            S.insert(d);
            pref = 10ll * pref + int(d - '0');
            break;
        }
        for (char d = '0'; d <= '9'; d++) if (S.size() + !S.count(d) <= k) {
            S.insert(d);
            pref = pref * pw[int(s.length()) - i - 1] + int(d - '0') * ones[int(s.length()) - i - 1];
            break;
        }
        printf("%d\n", pref);
    }
    return 0;
}