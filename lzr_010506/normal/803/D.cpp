#include <bits/stdc++.h>
using namespace std;
int k, n = 0;
int s[1000010];

inline int pd(int w)
{
    int ans = 1, len = 0;
    for (int i = 0; i < n; i ++) 
    {
        if (s[i] > w) return 1e9;
        if ((len += s[i]) > w) len = s[i], ++ans;
    }
    return ans;
}

int main()
{
    scanf("%d\n", &k);
    int cur_len = 0;
    char ch;
    while ((ch = getchar()) != '\n') 
    {
        ++ cur_len;
        if (ch == ' ' || ch == '-') s[n ++] = cur_len, cur_len = 0;
    }
    s[n ++] = cur_len;

    int lo = 0, hi = 1e6 + 10, mid;
    while (lo < hi - 1) 
    {
        mid = (lo + hi) >> 1;
        if (pd(mid) <= k) hi = mid; 
        else lo = mid;
    }

    printf("%d\n", hi);
    return 0;
}