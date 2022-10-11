#include <iostream>
#include <cstdio>
using namespace std;

struct node
{
    int val;
    node *bit[2];
    node()
    {
        bit[0] = bit[1] = NULL;
        val = 0;
    }
};

char c;
node *root;
int n, x;

void build(int a)
{
    node *cur = root;
    for (int i = 30; i >= 0; i--)
    {
        if (cur -> bit[(a >> i) & 1] == NULL)
            cur -> bit[(a >> i) & 1] = new node();
        cur = cur -> bit[(a >> i) & 1];
        ++(cur -> val);
    }
}

void destroy(int a)
{
    node *cur = root;
    for (int i = 30; i >= 0; i--)
    {
        --(cur -> bit[(a >> i) & 1] -> val);
        if (cur -> bit[(a >> i) & 1] -> val == 0)
        {
            cur -> bit[(a >> i) & 1] = NULL;
            return;
        }
        else cur = cur -> bit[(a >> i) & 1];
    }
}

int get_ans(int a)
{
    node *cur = root;
    int ans = 0;
    for (int i = 30; i >= 0; i--)
    {
        if (cur -> bit[1 ^ ((a >> i) & 1)] == NULL)
            cur = cur -> bit[(a >> i) & 1];
        else
        {
            ans += (1 << i);
            cur = cur -> bit[1 ^ ((a >> i) & 1)];
        }
    }
    return ans;
}

int main()
{
    //freopen("MULTISET.inp", "r", stdin); freopen("MULTISET.out", "w", stdout);
    root = new node();
    build(0);
    scanf("%d\n", &n);
    while (n--)
    {
        scanf("%c %d\n", &c, &x);
        if (c == '+')
            build(x);
        else if (c == '-')
            destroy(x);
        else printf("%d\n", get_ans(x));
    }
}