#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int fir; scanf("%d", &fir);
        bool sam = true;
        for (int i = 2; i <= n; i++) {
            int num; scanf("%d", &num);
            if (num != fir) sam = false;
        }
        printf("%d\n", sam? n: 1);
    }
    return 0;
}