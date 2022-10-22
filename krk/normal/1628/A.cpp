#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
deque <int> D[Maxn];
vector <int> B;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i <= n + 1; i++)
            D[i].clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            D[a].push_back(i);
        }
        B.clear();
        int pnt = 0;
        while (pnt < n) {
            int nxt = 0, mx = pnt;
            while (!D[nxt].empty()) {
                mx = max(mx, D[nxt].front());
                nxt++;
            }
            for (int i = 0; i < nxt; i++)
                while (!D[i].empty() && D[i].front() <= mx)
                    D[i].pop_front();
            B.push_back(nxt);
            pnt = mx + 1;
        }
        printf("%d\n", int(B.size()));
        for (int i = 0; i < B.size(); i++)
            printf("%d%c", B[i], i + 1 < B.size()? ' ': '\n');
    }
    return 0;
}