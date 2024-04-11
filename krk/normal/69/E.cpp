#include <cstdio>
#include <map>
#include <set>
using namespace std;

const int Maxn = 100000;

int n, k, a[Maxn];
set <int> S;
map <int, int> M;

int main()
{
    set <int>::iterator it;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        M[a[i]] = 0;
    }
    int r = 0, tmp;
    for (int i = k; i <= n; i++) {
        while (r < i) {
              tmp = ++M[a[r]];
              if (tmp == 1) S.insert(a[r]);
              else if (tmp == 2) S.erase(a[r]);
              r++;
        }
        if (S.empty()) printf("Nothing\n");
        else {
             it = S.end(); it--;
             printf("%d\n", *it);
        }
        tmp = --M[a[i-k]];
        if (tmp == 1) S.insert(a[i-k]);
        else if (tmp == 0) S.erase(a[i-k]);
    }
    return 0;
}