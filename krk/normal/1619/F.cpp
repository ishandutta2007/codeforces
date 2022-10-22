#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, k;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        vector <int> siz;
        int num = n, dv = m;
        while (dv > 0) {
            siz.push_back(num / dv);
            num -= num / dv;
            dv--;
        }
        int st = 0;
        for (int i = 0; i < siz.size(); i++)
            st += siz[i] == siz.back();
        st *= siz.back();
        int cur = 0;
        for (int i = 0; i < k; i++) {
            int nxt = cur;
            for (int j = 0; j < siz.size(); j++) {
                printf("%d", siz[j]);
                for (int k = 0; k < siz[j]; k++) {
                    printf(" %d", nxt + 1);
                    nxt = (nxt + 1) % n;
                }
                printf("\n");
            }
            cur = (cur + st) % n;
        }
        if (T) printf("\n");
    }
    return 0;
}