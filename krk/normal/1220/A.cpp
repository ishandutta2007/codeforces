#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int ns;

int main()
{
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'n') ns++;
    int zers = (n - 3 * ns) / 4;
    while (ns--) printf("1 ");
    while (zers--) printf("0 ");
    printf("\n");
    return 0;
}