#include <bits/stdc++.h>
using namespace std;

int n, k;
map <int, int> M;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int a; scanf("%d", &a);
        M[a] = i;
    }
    if (M.size() < k) printf("NO\n");
    else {
        printf("YES\n");
        bool pr = false;
        for (auto it = M.begin(); it != M.end() && k > 0; it++, k--) {
            if (pr) printf(" ");
            else pr = true;
            printf("%d", it->second);
        }
        printf("\n");
    }
    return 0;
}