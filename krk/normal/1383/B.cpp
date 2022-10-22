#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int Maxb = 30;

int T;
int n;
int a[Maxn];

string Solve()
{
    for (int i = Maxb - 1; i >= 0; i--) {
        int ones = 0, zers = 0;
        for (int j = 0; j < n; j++)
            if (a[j] & 1 << i) ones++;
            else zers++;
        if (ones % 2)
            if ((ones - 1) % 4 == 0) return "WIN";
            else return zers % 2 == 0? "LOSE": "WIN";
    }
    return "DRAW";
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%s\n", Solve().c_str());
    }
    return 0;
}