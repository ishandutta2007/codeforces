#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int nd;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        nd = n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            while (nd > 0 && a[i] % 2 == 0) {
                nd--; a[i] /= 2;
            }
        }
        vector <int> seq;
        for (int i = 1; i <= n; i++) {
            int num = i, cnt = 0;
            while (num % 2 == 0) {
                cnt++; num /= 2;
            }
            seq.push_back(cnt);
        }
        sort(seq.rbegin(), seq.rend());
        int pnt = 0;
        while (pnt < seq.size() && nd > 0)
            nd -= seq[pnt++];
        printf("%d\n", nd > 0? -1: pnt);
    }
    return 0;
}