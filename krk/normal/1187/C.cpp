#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int lim = 100000000;
const int Maxn = 10005;

int pnt = lim;
int n, m;
vector <ii> seq, ch;
int res[Maxn];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int t, l, r; scanf("%d %d %d", &t, &l, &r); l--; r--;
        if (t == 1) seq.push_back(ii(l, r));
        else ch.push_back(ii(l, r));
    }
    vector <ii> tmp;
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++)
        if (tmp.empty() || tmp.back().second < seq[i].first)
            tmp.push_back(seq[i]);
        else tmp.back().second = max(tmp.back().second, seq[i].second);
    int nxt = 0;
    for (int i = 0; i < tmp.size(); i++) {
        while (nxt < tmp[i].first)
            res[nxt++] = pnt--;
        for (int j = tmp[i].first; j <= tmp[i].second; j++)
            res[nxt++] = pnt;
        pnt--;
    }
    while (nxt < n)
        res[nxt++] = pnt--;
    for (int i = 0; i < ch.size(); i++)
        if (res[ch[i].first] == res[ch[i].second]) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}