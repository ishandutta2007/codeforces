#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main()
{
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (a == 0) printf("1\n");
        else printf("%d\n", 2 * b + a + 1);
    }
    return 0;
}