#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1E5 + 5;

struct SNode
{
    int mi;
    SNode *bit[2];

    SNode()
    {
        mi = MAX;
        bit[0] = bit[1] = nullptr;
    }
} *rt[MAX];
vector<int> di[MAX];
int q, t, u, k, x, s;
bool chk[MAX];

void init()
{
    for (int i = 1; i < MAX; i++)
    {
        for (int j = i; j < MAX; j += i)
            di[j].push_back(i);
        rt[i] = new SNode();
    }
}

void add(int k, int u)
{
    SNode *cur = rt[k];
    cur->mi = min(cur->mi, u);
    for (int i = 18; i >= 0; i--)
    {
        if (cur->bit[u >> i & 1] == nullptr)
            cur->bit[u >> i & 1] = new SNode();
        cur = cur->bit[u >> i & 1];
        cur->mi = min(cur->mi, u);
    }
}

int que(int x, int k, int s)
{
    SNode *cur = rt[k];
    if (x % k != 0 || cur->mi + x > s)
        return -1;
    int ret = 0;
    for (int i = 18; i >= 0; i--)
    {
        int bi = x >> i & 1;
        if (cur->bit[bi ^ 1] != nullptr && cur->bit[bi ^ 1]->mi + x <= s)
        {
            ret += ((bi ^ 1) << i);
            cur = cur->bit[bi ^ 1];
        }
        else
        {
            ret += (bi << i);
            cur = cur->bit[bi];
        }
    }
    return ret;
}

int main()
{
    init();
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d", &u);
            if (!chk[u])
            {
                chk[u] = true;
                for (int k : di[u])
                    add(k, u);
            }
        }
        else
        {
            scanf("%d%d%d", &x, &k, &s);
            printf("%d\n", que(x, k, s));
        }
    }
    return 0;
}