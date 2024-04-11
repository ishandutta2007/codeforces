#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
int a[Maxn], b[Maxn];
int wh[Maxn];
int p[Maxn];
bool tk[Maxn];
int ids[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            wh[a[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            p[i] = wh[b[i]];
            tk[i] = false;
        }
        int lef = 1, rig = n;
        ll res = 0ll;
        for (int i = 1; i <= n; i++) if (!tk[i]) {
            vector <int> seq;
            int num = i;
            while (!tk[num]) {
                seq.push_back(num);
                tk[num] = true;
                num = p[num];
            }
            if (seq.size() % 2) seq.pop_back();
            for (int i = 0; i < seq.size(); i++)
                if (i % 2 == 0) ids[i] = lef++;
                else ids[i] = rig--;
            for (int i = 0; i < seq.size(); i++)
                res += abs(ids[i] - ids[(i + 1) % int(seq.size())]);
        }
        printf("%I64d\n", res);
    }
    return 0;
}