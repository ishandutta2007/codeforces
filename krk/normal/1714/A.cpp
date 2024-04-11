#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int T;
int n, H, M;
set <ii> S;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &H, &M);
        S.clear();
        for (int i = 0; i < n; i++) {
            int h, m; scanf("%d %d", &h, &m);
            S.insert(ii(h, m));
        }
        int res = 0;
        while (S.find(ii(H, M)) == S.end()) {
            res++;
            M++;
            if (M >= 60) { H++; M = 0; }
            if (H >= 24) H = 0;
        }
        printf("%d %d\n", res / 60, res % 60);
    }
    return 0;
}