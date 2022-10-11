#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct TNode
{
    TNode *bit[2] = {nullptr};
    bool e = false;
} *root = new TNode;
int n, a[1005], b[1005], i;
string ans[1005];

inline bool cmp(const int &x, const int &y)
{
    return a[x] < a[y];
}

void add(const int &a, string &s, TNode *cur)
{
    if (!a)
    {
        cur->e = true;
        return;
    }
    if (cur->bit[0] == nullptr || !cur->bit[0]->e)
    {
        s += '0';
        if (cur->bit[0] == nullptr)
            cur->bit[0] = new TNode;
        add(a - 1, s, cur->bit[0]);
    }
    else if (cur->bit[1] == nullptr || !cur->bit[1]->e)
    {
        s += '1';
        if (cur->bit[1] == nullptr)
            cur->bit[1] = new TNode;
        add(a - 1, s, cur->bit[1]);
    }
    else
    {
        printf("NO");
        exit(0);
    }
    if (cur->bit[0] != nullptr && cur->bit[0]->e && cur->bit[1] != nullptr && cur->bit[1]->e)
        cur->e = true;
}

int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        b[i] = i;
    }
    sort(b + 1, b + n + 1, cmp);
    for (i = 1; i <= n; i++)
        add(a[b[i]], ans[b[i]], root);
    printf("YES\n");
    for (i = 1; i <= n; i++)
        printf("%s\n", ans[i].c_str());
}