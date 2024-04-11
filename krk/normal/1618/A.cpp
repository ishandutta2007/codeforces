#include <bits/stdc++.h>
using namespace std;

const int Maxd = 7;

int T;
int b[Maxd];

int main()
{
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < Maxd; i++)
            scanf("%d", &b[i]);
        int n1 = b[0], n2 = b[1];
        int n3 = n1 + n2 == b[2]? b[3]: b[2];
        printf("%d %d %d\n", n1, n2, n3);
    }
    return 0;
}