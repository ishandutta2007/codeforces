#include <cstdio>
#include <string>
using namespace std;

const int Inf = 2000000000;

int n, r;
int best = Inf;
int bwth;
string res;

void Try(int v, int t, int b, int wth, int m)
{
    if (t == 0) {
        if (v == 0 && b == 1 && m < best) {
            best = m; bwth = wth;
        }
    } else {
        int tims;
        if (t < b) {
            tims = b / t - (b % t == 0);
            v -= tims;
            if (v < 0) return;
            b -= tims * t;
            m += tims - 1;
        } else {
            tims = t / b;
            v -= tims;
            if (v < 0) return;
            t -= tims * b;
            m += tims - 1;
        }
        Try(v, t, b, wth, m);
    }
}

int main()
{
    scanf("%d %d", &n, &r);
    for (int i = 1; i <= r; i++) { Try(n, i, r, 2 * i, 0); Try(n, r, i, 2 * i + 1, 0); }
    if (best == Inf) printf("IMPOSSIBLE\n");
    else {
        printf("%d\n", best);
        res.resize(n);
        int t, b;
        if (bwth % 2) { t = r; b = bwth / 2; }
        else { t = bwth / 2; b = r; }
        for (int i = n - 1; i >= 0; i--)
            if (t < b) {
                b -= t;
                res[i] = 'B';
            } else {
                t -= b;
                res[i] = 'T';
            }
        printf("%s\n", res.c_str());
    }
    return 0;
}