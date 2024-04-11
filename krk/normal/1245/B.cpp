#include <bits/stdc++.h>
using namespace std;

string lets = "RPS";

int t;
int n;
int my[3];
char str[1000], res[1000];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%d %d %d", &my[0], &my[1], &my[2]);
        scanf("%s", str);
        int wn = 0;
        for (int i = 0; i < n; i++) {
            int ind = lets.find(str[i]);
            ind = (ind + 1) % 3;
            if (my[ind] > 0) { res[i] = lets[ind]; my[ind]--; wn++; }
            else res[i] = '?';
        }
        if (wn >= (n + 1) / 2) {
            printf("YES\n");
            for (int i = 0; i < n; i++) if (res[i] == '?')
                for (int j = 0; j < 3; j++) if (my[j] > 0) {
                    res[i] = lets[j]; my[j]--; break;
                }
            res[n] = '\0';
            printf("%s\n", res);
        } else printf("NO\n");
    }
    return 0;
}