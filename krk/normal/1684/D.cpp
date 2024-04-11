#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        ll res = 0;
        vector <int> seq;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            res += a + k;
            seq.push_back(a + i + k);
        }
        sort(seq.rbegin(), seq.rend());
        for (int i = 0; i < k; i++)
            res -= (seq[i] - i);
        printf("%I64d\n", res);
    }
    return 0;
}