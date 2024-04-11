#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

int n;
int a[Maxn];
int st[Maxn];
int cnt;
vector <int> res;

bool Update(int x)
{
    if (x > 0) {
        if (st[x]++ == 0)
            cnt++;
        return true;
    } else {
        x = -x;
        if (st[x] == 0) return false;
        if (--st[x] == 0)
            cnt--;
        return true;
    }
}

bool Check(int l, int r)
{
    set <int> S;
    for (int i = l; i <= r; i++) if (a[i] > 0)
        if (S.find(a[i]) != S.end()) return false;
        else S.insert(a[i]);
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0, j; i < n; i = j) {
        if (!Update(a[i])) { printf("-1\n"); return 0; }
        j = i + 1;
        while (j < n && cnt > 0) {
            if (!Update(a[j])) { printf("-1\n"); return 0; }
            j++;
        }
        if (cnt > 0 || !Check(i, j - 1)) { printf("-1\n"); return 0; }
        res.push_back(j - i);
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}