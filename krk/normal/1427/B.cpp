#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, k;
char str[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        scanf("%s", str);
        int L = 0;
        int res = 0;
        int lst = -1;
        vector <int> seq;
        for (int i = 0; i < n; i++)
            if (str[i] == 'W') {
                res++;
                if (lst != -1) seq.push_back(i - lst - 1);
                lst = i;
            } else L++;
        if (L <= k) printf("%d\n", n + n - 1);
        else if (res == 0) printf("%d\n", max(0, k + k - 1));
        else {
            res += 2 * k;
            sort(seq.begin(), seq.end());
            for (int i = 0; i < seq.size(); i++) if (seq[i] <= k) {
                res++;
                k -= seq[i];
            }
            printf("%d\n", res);
        }
    }
    return 0;
}