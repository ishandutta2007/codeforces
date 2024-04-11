#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")
#include <bits/stdc++.h>

const int max_n = 200001;

char s[max_n];
int good[max_n];
int m[max_n];
std::vector<int> d[max_n];

int cnt(int* l, int* r, int* to) {
    int ans = 0;
    while(r < to) {
        ans += good[*r++ - *l++];
    }
    return ans;
}

int main()
{
    int n;
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        m[i + 1] = m[i] + s[i] - '0';
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            d[j].push_back(i);
        }
    }
    for (int len = 1; len <= n; ++len) {
        for (int a : d[len]) good[a] = 1;
        ans += cnt(m, m + len, m + n + 1);
        for (int a : d[len]) good[a] = 0;
    }
    printf("%I64d", ans);
    return 0;
}