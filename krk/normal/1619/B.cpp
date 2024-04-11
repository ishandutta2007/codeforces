#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll l = 1, r = 1;
        ll vall = 1, valr = 1;
        int res = 0;
        while (vall <= n || valr <= n) {
            res++;
            if (vall < valr) {
                l++;
                vall = l * l;
            } else if (vall > valr) {
                r++;
                valr = r * r * r;
            } else {
                l++; vall = l * l;
                r++; valr = r * r * r;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}