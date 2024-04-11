#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int64_t MS = 10000000000000000ll;
int64_t f[19], ans, c[26];
map<int64_t, int64_t, greater<int64_t>> m[26];
map<int64_t, int64_t, greater<int64_t>> m2[26];

void fact(int64_t n, int64_t &ans)
{
    return n?fact(n - 1, ans *= n):void();
}


int main()
{
    int64_t n = 25, k = 25, s = 1;
    cin >> n >> k >> s;
    int64_t mid = n / 2;
    for (int i = 0; i < n; ++i)
    {
//        c[i] = (1 << i);
        cin >> c[i];
        if (c[i] < 19 && !f[c[i]])
            f[c[i]] = 1, fact(c[i], f[c[i]]);
    }
    m[0][0] = 1;
    for (int i = 0; i < mid; ++i)
        for (int uam = k; uam > -1; --uam)
            for (auto j: m[uam])
            {
                auto t = j;
                if (t.first + c[i] <= MS)
                    m[uam][t.first + c[i]] += t.second;
                if (c[i] < 19 && t.first + f[c[i]] <= MS)
                    m[uam + 1][t.first + f[c[i]]] += t.second;
//                j = t;
            }
    m2[0][0] = 1;
    for (int i = mid; i < n; ++i)
        for (int uam = k; uam > -1; --uam)
            for (auto j: m2[uam])
            {
                auto t = j;
                if (t.first + c[i] <= MS)
                    m2[uam][t.first + c[i]] += t.second;
                if (c[i] < 19 && t.first + f[c[i]] <= MS)
                    m2[uam + 1][t.first + f[c[i]]] += t.second;
//                j = t;
            }
    for (int am1 = 0; am1 <= k; ++am1)
        for (int am2 = 0; am1 + am2 <= k; ++am2)
            for (auto i: m[am1])
                if (m2[am2].count(s - i.first))
                    ans += m2[am2][s - i.first] * i.second;
    cout << ans;
    return 0;
}