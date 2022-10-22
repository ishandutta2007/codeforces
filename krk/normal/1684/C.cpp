#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, m;
vector <int> B[Maxn];
int myi[Maxn], myj[Maxn];
int bi, bj;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        bi = bj = 0;
        for (int i = 0; i < n; i++) {
            B[i].resize(m);
            for (int j = 0; j < m; j++)
                scanf("%d", &B[i][j]);
            if (bi == -1) continue;
            vector <int> tmp = B[i];
            sort(tmp.begin(), tmp.end());
            vector <int> seq;
            for (int j = 0; j < m; j++)
                if (B[i][j] != tmp[j])
                    seq.push_back(j);
            if (seq.empty()) {
                myi[i] = 0, myj[i] = 0;
                continue;
            }
            if (seq.size() > 2) bi = bj = -1;
            else {
                myi[i] = seq[0], myj[i] = seq[1];
                if (bi == 0 && bj == 0 || bi == myi[i] && bj == myj[i]) {
                    bi = myi[i];
                    bj = myj[i];
                } else bi = bj = -1;
            }
        }
        if (bi == -1) { printf("-1\n"); continue; }
        if (bi != 0 || bj != 0) {
            for (int i = 0; i < n && bi != -1; i++) if (myi[i] == 0 && myj[i] == 0)
                if (B[i][bi] != B[i][bj]) bi = bj = -1;
            if (bi == -1) { printf("-1\n"); continue; }
        }
        printf("%d %d\n", bi + 1, bj + 1);
    }
    return 0;
}