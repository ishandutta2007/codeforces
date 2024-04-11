#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int Maxn = 500005;
const int lim = 1000000000;

struct lady {
       int b, i, r;
       bool operator <(const lady &l) const {
            return b != l.b? b < l.b: i != l.i? i > l.i: r < l.r;
       }
} L[Maxn];

int n;
map <int, int> M;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &L[i].b);
    for (int i = 0; i < n; i++) scanf("%d", &L[i].i);
    for (int i = 0; i < n; i++) scanf("%d", &L[i].r);
    sort(L, L + n);
    M[-lim] = lim; M[lim] = -lim;
    for (int i = n - 1; i >= 0; i--) {
        map <int, int>::iterator it = M.upper_bound(L[i].i);
        if (L[i].r < it->second) res++;
        else if (M[L[i].i] < L[i].r) {
                M[L[i].i] = L[i].r;
                for (it = --M.lower_bound(L[i].i); it->second < L[i].r; )
                    M.erase(it--);
             }
    }
    printf("%d\n", res);
    return 0;
}