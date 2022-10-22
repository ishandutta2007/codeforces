#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int P[Maxn];
deque <int> D;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        D.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &P[i]);
            if (D.empty() || P[i] < D.front())
                D.push_front(P[i]);
            else D.push_back(P[i]);
        }
        for (int i = 0; i < D.size(); i++)
            printf("%d%c", D[i], i + 1 < D.size()? ' ': '\n');
    }
    return 0;
}