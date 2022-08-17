#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 500111, inf = 1000111222;

int n;
int nxt[max_n];
int m[max_n];
bool bad = false;

void rec(int from, int to, int start) {
    int cnt = 0;
    for (int i = from; i <= to;) {
        ++cnt;
        if (nxt[i] > to + 1) {
            bad = true;
            return;
        }
        i = nxt[i];
    }
    int cur_sub = start;
    int cur_bord = start + (to - from) - cnt + 1;
    for (int i = from; i <= to;) {
        m[i] = cur_bord++;
        if (nxt[i] > i + 1) {
            rec(i + 1, nxt[i] - 1, start);
            if (bad) return;
            start += (nxt[i] - i - 1);
        }
        i = nxt[i];
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", nxt + i);
            nxt[i] = (nxt[i] == -1 ? i + 1 : nxt[i] - 1);
        }
        bad = false;
        rec(0, n - 1, 1);
        if (bad) {
            printf("%d\n", -1);
        } else {
            for (int i = 0; i < n; ++i) {
                printf("%d ", m[i]);
            }
            printf("\n");
        }
    }
    return 0;
}