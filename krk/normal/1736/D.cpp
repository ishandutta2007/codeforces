#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n); n *= 2;
        scanf("%s", str + 1);
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (str[i] == '1') sum++;
        if (sum % 2) { printf("-1\n"); continue; }
        char my = '0';
        vector <int> seq;
        for (int i = 1; i <= n; i += 2)
            if (str[i] != str[i + 1])
                if (str[i] != my) {
                    seq.push_back(i);
                    my = str[i];
                } else {
                    seq.push_back(i + 1);
                    my = str[i + 1];
                }
        printf("%d", int(seq.size()));
        for (int i = 0; i < seq.size(); i++)
            printf(" %d", seq[i]);
        printf("\n");
        bool pr = false;
        for (int i = 1; i <= n; i += 2) {
            if (pr) printf(" ");
            else pr = true;
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}