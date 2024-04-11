#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;

int n;
int x, y;

int Ask(int x, int y)
{
    printf("%d %d\n", x, y); fflush(stdout);
    string s; cin >> s;
    return s == "black";
}

int main()
{
    scanf("%d", &n);
    int lef = 2, rig = Inf - 2;
    for (int i = 1; i < n; i++) {
        int mid = lef + rig >> 1;
        if (Ask(mid, 1) == 1) lef = mid + 1;
        else rig = mid - 1;
    }
    lef--;
    int col = Ask(lef, 3);
    if (col == 1)
        printf("%d %d %d %d\n", lef + 1, 3, lef, 0);
    else printf("%d %d %d %d\n", lef - 1, 4, lef + 1, 0);
    return 0;
}