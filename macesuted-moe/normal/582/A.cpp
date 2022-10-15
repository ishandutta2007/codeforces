#include <bits/stdc++.h>
using namespace std;

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -f;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

const int maxn = 250005;

int a[maxn], ans[maxn];
map<int, int> bucket;

inline int gcd(int a, int b) { return (!a) ? b : gcd(b % a, a); }

int main(void) {
    int n = read<int>(), cnt = 0;
    for (int i = 1; i <= n * n; i++) {
        int x = read<int>();
        if (bucket.find(x) == bucket.end()) a[++cnt] = x;
        bucket[x]++;
    }
    sort(a + 1, a + cnt + 1, greater<int>());
    int num = 0;
    for (int i = 1; i <= cnt && num < n;) {
        while (!bucket[a[i]]) i++;
        ans[++num] = a[i];
        bucket[a[i]]--;
        for (int j = 1; j < num; j++) bucket[gcd(ans[j], a[i])] -= 2;
    }
    for (int i = 1; i <= num; i++) printf("%d ", ans[i]);
    puts("");
    return 0;
}