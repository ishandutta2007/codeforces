#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int max_n = 311111;

struct tower
{
    int ll = 0, lm = 0;
    int rl = 0, rm = 0;
    long long h = 0;
    int rad = 0;

    void add(tower &other)
    {
        ll += other.ll;
        lm += other.lm;
        rl += other.rl;
        rm += other.rm;
        h += other.h;
    }
    void clear()
    {
        ll = lm = rl = rm = h = rad = 0;
    }
};

tower tree[max_n * 4];
tower start[max_n];

int n;

void protalk(int cur, int l, int r)
{
    if (tree[cur].h == 0 &&
        tree[cur].ll == 0 &&
        tree[cur].lm ==0 &&
        tree[cur].rl == 0 &&
        tree[cur].rm == 0) return;
    if (l == r)
    {
        tree[cur].rad = 1 + tree[cur].ll + tree[cur].rl;
        return;
    }

    int newrad = tree[cur].rad + tree[cur].ll + tree[cur].rl;
    tree[cur * 2].add(tree[cur]);
    tree[cur * 2 + 1].add(tree[cur]);
    tree[cur].clear();
    tree[cur].rad = newrad;
}

void build_tree(int cur, int l, int r)
{
    if (l == r)
    {
        tree[cur] = start[l];
        return;
    }

    int mid = (l + r) / 2;
    build_tree(cur * 2, l, mid);
    build_tree(cur * 2 + 1, mid + 1, r);
    tree[cur].rad = max(tree[cur * 2].rad, tree[cur * 2 + 1].rad);
}

int getMaxMount()
{
    protalk(1, 0, n - 1);
    return tree[1].rad;
}

tower get(int cur, int l, int r, int pos)
{
    protalk(cur, l, r);
    if (l == r)
    {
        return tree[cur];
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
    {
        return get(cur * 2, l, mid, pos);
    }
    else
    {
        return get(cur * 2 + 1, mid + 1, r, pos);
    }
}

int add(int cur, int l, int r, int al, int ar, tower &t)
{
    protalk(cur, l, r);

    if (l == al && r == ar)
    {
        tree[cur].add(t);
        return (l == r ? 1 : tree[cur].rad) + tree[cur].ll + tree[cur].rl;
    }

    if (al > r || ar < l)
    {
        return tree[cur].rad;
    }

    int mid = (l + r) / 2;
    tree[cur].rad = max(add(cur * 2, l, mid, al, min(mid, ar), t),
                        add(cur * 2 + 1, mid + 1, r, max(al, mid + 1), ar, t));
    return tree[cur].rad;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &start[i].h);
    }

    start[0].ll = start[0].lm = 0;
    for (int i = 1; i < n; ++i)
    {
        if (start[i].h > start[i - 1].h)
        {
            start[i].ll = 1 + start[i - 1].ll;
            start[i].lm = 0;
        }
        else if (start[i].h < start[i - 1].h)
        {
            start[i].ll = 0;
            start[i].lm = start[i - 1].lm + 1;
        }
        else
        {
            start[i].ll = start[i].lm = 0;
        }
    }

    start[n - 1].rl = start[n - 1].rm = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        if (start[i].h > start[i + 1].h)
        {
            start[i].rm = 0;
            start[i].rl = start[i + 1].rl + 1;
        }
        else if (start[i].h < start[i + 1].h)
        {
            start[i].rl = 0;
            start[i].rm = start[i + 1].rm + 1;
        }
        else
        {
            start[i].rl = start[i].rm = 0;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        start[i].rad = 1 + start[i].ll + start[i].rl;
    }

    build_tree(1, 0, n - 1);


    int qNumber;
    cin >> qNumber;
    int l, r, h;
    for (int i = 0; i < qNumber; ++i)
    {
        scanf("%d%d%d", &l, &r, &h);
        if (h == 0)
        {
            printf("%d\n", getMaxMount());
            continue;
        }
        l--;
        r--;
        { // R
            tower t;

            if (r < n - 1)
            {
                tower cur = get(1, 0, n - 1, r);
                tower next = get(1, 0, n - 1, r + 1);
                if (cur.h <= next.h && cur.h + h > next.h)
                {
                    // 
                    t.ll = -next.ll;
                    if (t.ll) add(1, 0, n - 1, r + 1, r + 1 + next.rm, t);
                    t.ll = 0;
                    t.lm = cur.lm + 1;
                    if (t.lm) add(1, 0, n - 1, r + 1, r + 1 + next.rl, t);
                    t.lm = 0;

                    // 
                    t.rm = -cur.rm;
                    if (t.rm) add(1, 0, n - 1, r - cur.ll, r, t);
                    t.rm = 0;
                    t.rl = 1 + next.rl;
                    if (t.rl) add(1, 0, n - 1, r - cur.lm, r, t);
                    t.rl = 0;
                }
                else if (cur.h < next.h && cur.h + h == next.h)
                {
                    // 
                    t.ll = -next.ll;
                    if (t.ll) add(1, 0, n - 1, r + 1, r + 1 + next.rm, t);
                    t.ll = 0;

                    // 
                    t.rm = -cur.rm;
                    if (t.rm) add(1, 0, n - 1, r - cur.ll, r, t);
                    t.rm = 0;
                }
            }

            t.h = h;
            add(1, 0, n - 1, 0, r, t);
            t.h = 0;
        }

        if (l > 0)
        { // L
            r = l - 1;
            tower t;

            tower cur = get(1, 0, n - 1, r);
            tower next = get(1, 0, n - 1, r + 1);
            if (cur.h >= next.h && cur.h - h < next.h)
            {
                // 
                t.lm = -next.lm;
                if (t.lm) add(1, 0, n - 1, r + 1, r + 1 + next.rl, t);
                t.lm = 0;
                t.ll = cur.ll + 1;
                if (t.ll) add(1, 0, n - 1, r + 1, r + 1 + next.rm, t);
                t.ll = 0;

                // 
                t.rl = -cur.rl;
                if (t.rl) add(1, 0, n - 1, r - cur.lm, r, t);
                t.rl = 0;
                t.rm = 1 + next.rm;
                if (t.rm) add(1, 0, n - 1, r - cur.ll, r, t);
                t.rm = 0;
            }
            else if (cur.h > next.h && cur.h - h == next.h)
            {
                // 
                t.lm = -next.lm;
                if (t.lm) add(1, 0, n - 1, r + 1, r + 1 + next.rl, t);
                t.lm = 0;

                // 
                t.rl = -cur.rl;
                if (t.rl) add(1, 0, n - 1, r - cur.lm, r, t);
                t.rl = 0;
            }

            t.h = -h;
            add(1, 0, n - 1, 0, r, t);
            t.h = 0;
        }

        printf("%d\n", getMaxMount());
    }

    return 0;
}