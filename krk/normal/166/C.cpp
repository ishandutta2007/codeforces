#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;

int n, x;
set <ii> S;
int res;

int main()
{
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        S.insert(make_pair(a, i));
    }
    set <ii>::iterator it = S.begin();
    int cnt = (S.size() - 1) / 2;
    while (cnt--) it++;
    while (it->first != x) {
        S.insert(make_pair(x, n + res));
        res++;
        if (make_pair(x, n + res) < *it && S.size() % 2 == 0) it--;
        else if (*it < make_pair(x, n + res) && S.size() % 2 == 1) it++;
    }
    printf("%d\n", res);
    return 0;
}