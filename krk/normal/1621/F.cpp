#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n, a, b, c;
char str[Maxn];

ll Solve(deque <int> D, int zers, int ones, int lef, int rig)
{
    ll res = 0;
    while (true) {
        while (!D.empty() && D.front() == 1) { ones++; D.pop_front(); }
        while (ones > 0 && b > c) { ones--; res += b - c; }
        if (!D.empty()) { D.front()--; res += a; }
        else if (lef > 1) { lef--; res += a; }
        else if (rig > 1) { rig--; res += a; }
        else if (lef == 1 && b > c && zers > 0) { lef--; res -= c; }
        else if (rig == 1 && b > c && zers > 0) { rig--; res -= c; }
        else return res;
        if (zers > 0) { zers--; res += b; }
        else return res;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &a, &b, &c);
        scanf("%s", str);
        deque <int> D;
        int zers = 0, ones = 0;
        int lef = 0;
        while (lef < n && str[lef] == '0') lef++;
        int rig = 0;
        while (lef + rig < n && str[n - 1 - rig] == '0') rig++;
        for (int i = lef, j; i < n - 1 - rig; i = j) {
            j = i + 1;
            while (str[j] != '1') j++;
            int got = j - i - 1;
            if (got == 0) zers++;
            else if (got == 1) ones++;
            else D.push_back(got);
        }
        sort(D.begin(), D.end());
        ll res = Solve(D, zers, ones, lef, rig);
        if (zers > 0) res = max(res, Solve(D, zers - 1, ones, lef, rig) + b);
        printf("%I64d\n", res);
    }
    return 0;
}