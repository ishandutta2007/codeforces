#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, q, type, w;
vector<int> V[N];
bool read[N];

int main() {

    scanf("%d %d", &n, &q);

    int lastRead = 0;
    int pos = 0;
    int ans = 0;
    while (q--) {
        scanf("%d %d", &type, &w);
        if (type == 1) {
            ans++;
            pos++;
            V[w].push_back(pos);
        } else if (type == 2) {
            for (int i = 0; i < V[w].size(); i++) {
                int p = V[w][i];
                if (lastRead < p) {
                    ans--;
                }
                read[p] = true;
            }
            V[w].clear();
        } else {
            for (int i = lastRead + 1; i <= w; i++) {
                if (read[i] == false) {
                    ans--;
                }
            }
            lastRead = max(lastRead, w);
        }
        printf("%d\n", ans);
    }

    return 0;
}