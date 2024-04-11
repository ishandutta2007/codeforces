#include <bits/stdc++.h>
using namespace std;

int T;
int n, r, b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &r, &b);
        while (b) {
            int tk = r / (b + 1);
            printf("%s", string(tk, 'R').c_str());
            r -= tk;
            printf("B");
            b--;
        }
        if (r) printf("%s", string(r, 'R').c_str());
        printf("\n");
    }
    return 0;
}