#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400005;

int n;
map <int, int> M;
int tims[Maxn];
int best = 0, bi, bj;
vector <vector <int> > B;
vector <int> pnt;
vector <ii> seq;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        tims[++M[a]]++;
    }
    int tot = 0;
    for (int i = 1; i < Maxn; i++) {
        tot += tims[i];
        int j = tot / i;
        if (i <= j && i * j > best) { best = i * j; bi = i; bj = j; }
    }
    B.resize(bi);
    pnt.resize(bi);
    for (int i = 0; i < bi; i++) {
        B[i].resize(bj);
        pnt[i] = i;
    }
    for (auto it: M)
        seq.push_back(ii(min(it.second, bi), it.first));
    sort(seq.rbegin(), seq.rend());
    int r = 0;
    for (int i = 0; i < seq.size(); i++)
        for (int j = 0; j < seq[i].first; j++) {
            B[r][pnt[r]] = seq[i].second;
            pnt[r] = (pnt[r] + 1) % bj;
            r = (r + 1) % bi;
        }
    printf("%d\n", best);
    printf("%d %d\n", bi, bj);
    for (int i = 0; i < bi; i++)
        for (int j = 0; j < bj; j++)
            printf("%d%c", B[i][j], j + 1 < bj? ' ': '\n');
    return 0;
}