#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <int> seq;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (i > 1 && a[i - 1] == a[i])
                seq.push_back(i - 1);
        }
        if (seq.size() <= 1) printf("0\n");
        else printf("%d\n", max(1, seq.back() - seq[0] - 1));
    }
    return 0;
}