#include <bits/stdc++.h>
using namespace std;

int Ask(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
    char ch; scanf(" %c", &ch);
    if (ch == 'x') return 0;
    else if (ch == 'y') return 1;
    else return 2;
}

void Print(int a)
{
    printf("! %d\n", a);
    fflush(stdout);
}

int main()
{
    string s;
    while (cin >> s) {
        if (s == "mistake" || s == "end") break;
        int g = Ask(0, 1);
        if (g == 2) return 0;
        if (g == 0) { Print(1); continue; }
        g = Ask(1, 2);
        if (g == 2) return 0;
        if (g == 0) { Print(2); continue; }
        int l = 3, r;
        while (true) {
            r = 2 * l;
            int g = Ask(l, r);
            if (g == 2) return 0;
            if (g == 0) break;
            l = r + 1;
        }
        r = 2 * l;
        int lef = l, rig = min(1000000000, r);
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            int g = Ask(mid / 2, mid);
            if (g == 2) return 0;
            if (g == 0) rig = mid - 1;
            else lef = mid + 1;
        }
        rig++;
        Print(rig);
    }
    return 0;
}