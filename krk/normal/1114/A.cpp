#include <bits/stdc++.h>
using namespace std;

int x, y, z;
int a, b, c;

int main()
{
    cin >> x >> y >> z;
    cin >> a >> b >> c;
    int cur = a;
    if (x > cur) { printf("NO\n"); return 0; }
    cur -= x;
    cur += b;
    if (y > cur) { printf("NO\n"); return 0; }
    cur -= y;
    cur += c;
    if (z > cur) { printf("NO\n"); return 0; }
    printf("YES\n");
    return 0;
}