#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1001;
const int H = 10;

short t[H][H][N][N];
int LOG[N];
int a[N][N];
int val[N][N];
int n, m;

void init() {
    int c = 0;
    for (int i = 0; i < N; i++) {
        while ((1 << (c + 1)) <= i)
            c++;
        LOG[i] = c;
    }
    for (int hi = 0; hi < H; hi++)
        for (int hj = 0; hj < H; hj++) 
            for (int i = 0; i + (1 << hi) <= n; i++)
                for (int j = 0; j + (1 << hj) <= m; j++) {
                    t[hi][hj][i][j] = val[i][j];
                    int di = 1 << max(0, (hi - 1));
                    int dj = 1 << max(0, (hj - 1));
                    if (hi) 
                        t[hi][hj][i][j] = max(t[hi - 1][hj][i + di][j], t[hi - 1][hj][i][j]);
                    else if (hj) 
                        t[hi][hj][i][j] = max(t[hi][hj - 1][i][j + dj], t[hi][hj - 1][i][j]);
                }
}
 
int get_max(int lx, int ly, int rx, int ry) {
    int lenx = rx - lx + 1;
    int leny = ry - ly + 1;
    int hx = LOG[lenx];
    int hy = LOG[leny];
    int dx = 1 << hx;
    int dy = 1 << hy;
    short res = t[hx][hy][lx][ly];
    res = max(res, t[hx][hy][rx - dx + 1][ly]);
    res = max(res, t[hx][hy][lx][ry - dy + 1]);
    res = max(res, t[hx][hy][rx - dx + 1][ry - dy + 1]);
    return res;
}

int get_sum(int lx, int ly, int rx, int ry) {
    int res = a[rx][ry];
    res -= lx ? a[lx - 1][ry] : 0;
    res -= ly ? a[rx][ly - 1] : 0;
    res += lx && ly ? a[lx - 1][ly - 1] : 0;
    return res;
}
    
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            a[i][j] += i ? a[i - 1][j] : 0;
            a[i][j] += j ? a[i][j - 1] : 0;
            a[i][j] -= i && j ? a[i - 1][j - 1] : 0;
        }
    auto start = clock();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int low = 0;
            int high = min(n - i + 1, m - j + 1);
            while (high - low > 1) {
                int mid = (low + high) / 2;
                if (get_sum(i, j, i + mid - 1, j + mid - 1) == mid * mid)
                    low = mid;
                else
                    high = mid;
            }
            val[i][j] = low;
        }
    }
    cerr << (clock() - start) * 1.0 / CLOCKS_PER_SEC << endl;
    auto start2 = clock();
    init();
    cerr << (clock() - start2) * 1.0 / CLOCKS_PER_SEC;
    int q;
    scanf("%d", &q);
    while (q--) {
        int lx, ly, rx, ry;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        --lx;
        --ly;
        --rx;
        --ry;
        int low = 0;
        int high = min(rx - lx + 2, ry - ly + 2);
        while (high - low > 1) {
            int mid = (low + high) / 2;
            int nrx = rx - mid + 1;
            int nry = ry - mid + 1;
            if (get_max(lx, ly, nrx, nry) >= mid)
                low = mid;
            else
                high = mid;
        }
        printf("%d\n", low);
    }
}