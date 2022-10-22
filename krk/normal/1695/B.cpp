#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 52;
const int Inf = 1000000007;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if (n % 2) { printf("Mike\n"); continue; }
        ii A = ii(Inf, 0), B = ii(Inf, 0);
        for (int i = 0; i < n; i++)
            if (i % 2 == 0) A = min(A, ii(a[i], i));
            else B = min(B, ii(a[i], i));
        printf("%s\n", A <= B? "Joe": "Mike");
    }
    return 0;
}