#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int m[max_n];
int lst[max_n];
int val[max_n];
int mx[max_n];
int n, q;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", m + i);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int p, x;
            scanf("%d%d", &p, &x);
            --p;
            lst[p] = i;
            m[p] = x;
        } else {
            int x;
            scanf("%d", &x);
            val[i] = x;
        }
    }
    mx[q - 1] = val[q - 1];
    for (int i = q - 2; i >= 0; --i) {
        mx[i] = max(val[i], mx[i + 1]);
    }
    for (int i = 0; i < n; ++i) {
        m[i] = max(m[i], mx[lst[i]]);
        printf("%d ", m[i]);
    }
    return 0;
}