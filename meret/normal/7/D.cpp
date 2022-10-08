#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long LL;

int p[10000005];

char s[10000005];

int main() {
    gets(s + 1);
    int n = strlen(s + 1);
    s[n + 1] = '#';
    for (int i = 1; i <= n; ++i) {
        s[n + i + 1] = s[n - i + 1];
    }
    n = 2 * n + 1;
    for (int i = 2; i <= n; ++i) {
        p[i] = p[i - 1];
        while (p[i] && s[p[i] + 1] != s[i])
            p[i] = p[p[i]];
        if (s[p[i] + 1] == s[i])
            ++p[i];
    }
    memset(s, 0, sizeof(s));
    int c = p[n];
    while (c > 0) {
        s[c] = 1;
        c = p[c];
    }
    n /= 2;
    LL res = 0;
    for (int i = 1; i <= n; ++i) {
        if (!s[i])
            p[i] = 0;
        else
            p[i] = p[i / 2] + 1;
        res += p[i];
    }
    printf("%lld\n", res);
}