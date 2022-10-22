#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int b[Maxn];
iii seq[Maxn];
vector <iii> S;
char res[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            seq[i] = iii(ii(a[i], b[i]), i);
        }
        sort(seq, seq + n);
        S.clear();
        for (int i = 0; i < n; i++) {
            iii cur = iii(ii(seq[i].first.second, seq[i].first.second), 1);
            while (!S.empty() && S.back().first.second > cur.first.first) {
                cur.second += S.back().second;
                cur.first.first = min(cur.first.first, S.back().first.first);
                cur.first.second = max(cur.first.second, S.back().first.second);
                S.pop_back();
            }
            S.push_back(cur);
        }
        int hm = S.back().second;
        for (int i = 1; i <= hm; i++)
            res[seq[n - i].second] = '1';
        for (int i = hm + 1; i <= n; i++)
            res[seq[n - i].second] = '0';
        res[n] = '\0';
        printf("%s\n", res);
    }
    return 0;
}