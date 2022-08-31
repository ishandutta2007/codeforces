#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111;
int tree[max_n * 4] = {0};
int trees[max_n * 4] = {0};

void protalk(int cur, int l, int r)
{
    if (trees[cur] == 0) return;
    if (l == r)
    {
        tree[cur] += trees[cur];
        trees[cur] = 0;
        return;
    }
    tree[cur] += trees[cur];
    trees[cur * 2] += trees[cur];
    trees[cur * 2 + 1] += trees[cur];
    trees[cur] = 0;
}

void update(int cur, int l, int r, int sl, int sr, int val)
{
    protalk(cur, l, r);
    if (l == sl && r == sr)
    {
        trees[cur] += val;
        protalk(cur, l, r);
        return;
    }

    if (sl > r || sr < l)
    {
        return;
    }
    int mid = (l + r) / 2;
    update(cur * 2, l, mid, sl, min(mid, sr), val);
    update(cur * 2 + 1, mid + 1, r, max(sl, mid + 1), sr, val);
    tree[cur] = max(tree[cur * 2], tree[cur * 2 + 1]);
}

int getind(int cur, int l, int r)
{
    protalk(cur, l, r);
    if (tree[cur] <= 0)
    {
        return -1;
    }
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) / 2;
    protalk(cur * 2 + 1, l, mid);
    protalk(cur * 2 + 1, mid + 1, r);
    if (tree[cur * 2 + 1] > 0)
    {
        return getind(cur * 2 + 1, mid + 1, r);
    }
    else
    {
        return getind(cur * 2, l, mid);
    }
}

int arr[max_n] = {0};

int main()
{
    //ifstream cin("input.txt");
    int n, ind, op, a;
    cin >> n;
    for (int i = 0 ; i < n; ++i)
    {
        scanf("%d%d", &ind, &op);
        ind--;
        if (op == 0)
        {
            update(1, 0, n - 1, 0, ind, -1);
        }
        else
        {
            scanf("%d", &a);
            arr[ind] = a;
            update(1, 0, n - 1,0, ind, 1);
        }
        int in = getind(1, 0, n - 1);
        if (in == -1)
        {
            printf("%d\n", -1);
        }
        else
        {
            printf("%d\n", arr[in]);
        }
    }
}