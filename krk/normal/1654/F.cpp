#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxb = 18;
const int Maxn = 1 << Maxb;

int n;
char str[Maxn + 5];
int id[Maxn], nid[Maxn];
int seq[Maxn];
int cnt[Maxn];
ii tmp[Maxn];
int mask[Maxn];
char res[Maxn + 5];

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < 1 << n; i++) {
        id[i] = str[i] - 'a';
        tmp[i] = ii(id[i], i);
    }
    sort(tmp, tmp + (1 << n));
    for (int i = 0; i < 1 << n; i++)
        seq[i] = tmp[i].second;
    for (int b = 0; b < n; b++) {
        int sz = max(26, 1 << n);
        fill(cnt, cnt + sz, 0);
        for (int i = 0; i < 1 << n; i++)
            cnt[id[i]]++;
        int sum = 0;
        for (int i = 0; i < sz; i++) {
            int old = sum;
            sum += cnt[i];
            cnt[i] = old;
        }
        for (int i = 0; i < 1 << n; i++) {
            int v = seq[i];
            mask[cnt[id[v ^ 1 << b]]++] = (v ^ 1 << b);
        }
        int cur = -1;
        ii lst = ii(-1, -1);
        for (int i = 0; i < 1 << n; i++) {
            int v = mask[i];
            seq[i] = v;
            ii p = ii(id[v], id[v ^ 1 << b]);
            if (p != lst) {
                cur++;
                lst = p;
            }
            nid[v] = cur;
        }
        for (int i = 0; i < 1 << n; i++)
            id[i] = nid[i];
    }
    int v = seq[0];
    for (int i = 0; i < 1 << n; i++)
        res[v ^ i] = str[i];
    res[1 << n] = '\0';
    printf("%s\n", res);
    return 0;
}