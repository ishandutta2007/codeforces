#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 200005;

int T;
int n, s;
ll pref[Maxn];
int bi, bj;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &s);
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            int a; scanf("%d", &a);
            pref[i] = pref[i - 1] + a;
        }
        bi = 1, bj = 0;
        vector <lli> seq;
        seq.push_back(lli(pref[n], n));
        for (int i = n - 1; i >= 0; i--) {
            int ind = lower_bound(seq.begin(), seq.end(), lli(pref[i] - s, 0)) - seq.begin() - 1;
            int en = ind >= 0? seq[ind].second: n + 1;
            if (en - i - 1 >= bj - bi + 1) {
                bi = i + 1, bj = en - 1;
            }
            while (!seq.empty() && seq.back().first >= pref[i])
                seq.pop_back();
            seq.push_back(lli(pref[i], i));
        }
        if (bj - bi + 1 <= 0) printf("-1\n");
        else printf("%d %d\n", bi, bj);
    }
    return 0;
}