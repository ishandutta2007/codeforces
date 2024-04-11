#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int a, b, c, d;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ll fir = ll(a) * d, sec = ll(b) * c;
        if (fir == sec) printf("0\n");
        else {
            if (fir > sec) swap(fir, sec);
            if (fir == 0 || sec % fir == 0) printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}