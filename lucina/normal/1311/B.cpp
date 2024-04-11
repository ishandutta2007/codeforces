#include<cstdio>
#include<algorithm>
#include<list>
#include<numeric>

int a[105];
bool p[105];
int ord[105];

bool solve () {
    int n, m;
    scanf("%d %d", &n, &m);

    std::fill(p + 1 , p + 1 + n, false);
    std::iota(ord + 1 , ord + 1 + n, 1);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d", a + i);
    for (int i = 1 ; i <= m ; ++ i) {
        int x;
        scanf("%d", &x);
        p[x] = true;
    }

    for (int i = 1 ; i < n ; ++ i) {
        if (std::is_sorted(a + 1 , a + 1 + n))
            return true;
        int pos = std::min_element(a + i , a + 1 + n) - a;
        for (; pos > i ; -- pos) {
            if (p[pos - 1])
                std::swap(a[pos], a[pos - 1]);
        }
    }
    return std::is_sorted(a + 1 , a + 1 + n);
}

int main () {
    int T;
    for (scanf("%d", &T) ; T -- ; ) {
        puts(solve() ? "YES" : "NO");
    }
}