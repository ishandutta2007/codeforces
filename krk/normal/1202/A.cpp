#include <bits/stdc++.h>
using namespace std;

int t;
string a, b;

int main()
{
    cin >> t;
    while (t--) {
        cin >> a;
        cin >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int pnt = 0;
        while (b[pnt] != '1') pnt++;
        int pnt2 = pnt;
        while (a[pnt2] != '1') pnt2++;
        printf("%d\n", pnt2 - pnt);
    }
    return 0;
}