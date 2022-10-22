#include <bits/stdc++.h>
using namespace std;

int T;
int n, l, r, k;
vector <int> seq;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &l, &r, &k);
        seq.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (l <= a && a <= r) seq.push_back(a);
        }
        sort(seq.begin(), seq.end());
        int pnt = 0;
        while (pnt < seq.size() && seq[pnt] <= k) k -= seq[pnt++];
        printf("%d\n", pnt);
    }
    return 0;
}