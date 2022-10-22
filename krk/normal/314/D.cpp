#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
ii C[Maxn];
map <int, int> MX, MY;
double res = 10e30;

double getW(const map <int, int> &M)
{
    if (M.size() == 0) return 0;
    return (double(M.rbegin()->first) - double(M.begin()->first)) / 2.0;
}

void Add(map <int, int> &M, int x)
{
    M[x]++;
}

void Rem(map <int, int> &M, int x)
{
    if (--M[x] == 0) M.erase(x);
}

int main()
{
    int X, Y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X, &Y);
        C[i] = ii(Y + X, Y - X);
    }
    sort(C, C + n);
    for (int i = 0; i < n; i++)
        Add(MY, C[i].second);
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && (l == r || getW(MX) < getW(MY))) {
            res = min(res, max(getW(MX), getW(MY)));
            Rem(MY, C[r].second); Add(MX, C[r].first); r++;
        }
        res = min(res, max(getW(MX), getW(MY)));
        Rem(MX, C[l].first); Add(MY, C[l].second);
    }
    res = min(res, max(getW(MX), getW(MY)));
    printf("%.15lf\n", res);
    return 0;
}