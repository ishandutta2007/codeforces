#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
bool ment[Maxn];
bool tk[Maxn];
int b[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(ment + 1, ment + n + 1, false);
        fill(tk + 1, tk + n + 1, false);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ment[a[i]] = true;
            b[i] = a[i];
        }
        vector <int> seq;
        for (int i = 1; i <= n; i++) if (!ment[i]) {
            seq.push_back(i);
            tk[i] = true;
            while (!tk[a[seq.back()]]) {
                int nxt = a[seq.back()];
                tk[nxt] = true;
                seq.push_back(nxt);
            }
        } 
        if (!seq.empty())
            for (int i = 0; i < seq.size(); i++) {
                int ni = (i + 1) % int(seq.size());
                b[seq[i]] = seq[ni];
            }
        int res = 0;
        for (int i = 1; i <= n; i++)
            res += a[i] == b[i];
        printf("%d\n", res);
        for (int i = 1; i <= n; i++)
            printf("%d%c", b[i], i + 1 <= n? ' ': '\n');
    }
    return 0;
}