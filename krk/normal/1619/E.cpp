#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int freq[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
            freq[i] = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            freq[a]++;
        }
        ll res = 0;
        multiset <int> S;
        bool fall = false;
        for (int i = 0; i <= n; i++) {
            printf("%I64d%c", fall? -1ll: res + freq[i], i + 1 <= n? ' ': '\n');
            if (!fall) {
                for (int j = 0; j < freq[i]; j++)
                    S.insert(i);
                if (S.empty()) fall = true;
                else {
                    res += i - *S.rbegin();
                    auto it = S.end(); it--;
                    S.erase(it);
                }
            }
        }
    }
    return 0;
}