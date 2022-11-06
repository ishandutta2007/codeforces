#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
int a[N], k[N];
int cnt[N];

bool Check() {
    for (int i = 1; i <= m; ++i)
        if (cnt[i] != k[i]) return 0;
    return 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int sum = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &k[i]);
        sum += k[i];
    }
    for (int i = 1; i <= sum; ++i)
        ++cnt[a[i]];
    if (Check()) {
        puts("YES");
        return 0;
    }
    for (int i = sum + 1; i <= n; ++i) {
        ++cnt[a[i]];
        --cnt[a[i - sum]];
        if (Check()) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}