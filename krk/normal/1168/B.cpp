#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxl = 10;

int n;
char str[Maxn];
ll res;

int main()
{
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; i++) {
        int to = min(i + Maxl, n);
        bool ok = true;
        for (int j = i; j < to; j++) {
            for (int l = 1; 2 * l <= j - i && ok; l++)
                if (str[j] == str[j - l] && str[j - l] == str[j - 2 * l])
                    ok = false;
            if (ok) res++;
        }
    }
    cout << ll(n) * (n + 1) / 2 - res << endl;
    return 0;
}