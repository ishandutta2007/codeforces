#include <bits/stdc++.h>
using namespace std;

const int Maxn = 10005;

int T;
int n, k;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        int l = 0, r = n - 1;
        while (l < r && str[l] == str[r]) {
            l++;
            r--;
        }
        if (l >= r || k == 0) printf("1\n");
        else printf("2\n");
    }
    return 0;
}