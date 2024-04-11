#include <bits/stdc++.h>
using namespace std;

int c1, c2, c3, c4;

int main()
{
    cin >> c1 >> c2 >> c3 >> c4;
    if (c1 != c4) printf("0\n");
    else if (c3 > 0 && c1 == 0) printf("0\n");
    else printf("1\n");
    return 0;
}