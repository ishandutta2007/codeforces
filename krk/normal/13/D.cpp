#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, int> ldi;
typedef pair <int, int> ii;

const int Maxn = 1005;

int n, m;
ii pnt[Maxn];
vector <ldi> seq;
int C;
int res;

ll Cross(int a, int b, int c)
{
    int ax = pnt[b].first - pnt[a].first, ay = pnt[b].second - pnt[a].second;
    int bx = pnt[c].first - pnt[a].first, by = pnt[c].second - pnt[a].second;
    return ll(ax) * by - ll(ay) * bx;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n + m; i++)
        scanf("%d %d", &pnt[i].first, &pnt[i].second);
    sort(pnt, pnt + n);
    for (int i = 0; i < n; i++) {
        C = i;
        seq.clear();
        for (int j = i + 1; j < n + m; j++)
            seq.push_back(ldi(atan2(ld(pnt[j].second - pnt[C].second), ld(pnt[j].first - pnt[C].first)), j));
        sort(seq.begin(), seq.end());
        for (int j = 0; j < seq.size(); j++) if (seq[j].second < n) {
            int b = -1;
            for (int l = 1; l < seq.size(); l++) {
                int u = (j + l) % int(seq.size());
                if (Cross(C, seq[j].second, seq[u].second) < 0) break;
                if (seq[u].second < n)
                    res += b == -1 || Cross(seq[j].second, b, seq[u].second) > 0;
                else if (b == -1 || Cross(seq[j].second, b, seq[u].second) > 0) b = seq[u].second;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}