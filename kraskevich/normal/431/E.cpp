#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> PLL;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const int N = 1000 * 1000 * 1000 + 10;

struct Node
{
    Node *L, *R;
    LL sum;
    int cnt;
    int small;

    Node()
    {
        L = NULL;
        R = NULL;
        sum = 0;
        cnt = 0;
        small = N;
    }
};

Node buf[200 * 1000 * 32];
int sz = 0;

long long getSum(Node *t)
{
    return t ? t->sum : 0;
}

int getCnt(Node *t)
{
    return t ? t->cnt : 0;
}

int getSmall(Node *t)
{
    return t ? t->small : N;
}

Node* add(Node *t, int l, int r, int pos, PLL delta)
{
    if (t == NULL)
        t = &buf[sz++];
    t->sum += delta.F;
    t->cnt += delta.S;
    if (l == pos && r == pos)
    {
        if (t->cnt == 0)
            t->small = N;
        else
            t->small = pos;
        return t;
    }
    int m = (l + r) / 2;
    if (pos <= m)
        t->L = add(t->L, l, m, pos, delta);
    else
        t->R = add(t->R, m + 1, r, pos, delta);
    t->small = min(getSmall(t->L), getSmall(t->R));
    return t;
}

double solve(Node *t, int l, int r, double add, LL sumL, LL cntL)
{
    if (l == r)
    {
        sumL += t->sum;
        cntL += t->cnt;
        //cerr << sumL <<  " " << cntL << endl;
        return max((double)l, (sumL + add) / cntL);
    }
    assert(t);
    int m = (l + r) / 2;
    int small = getSmall(t->R);
    if (getCnt(t->L) == 0)
        return solve(t->R, m + 1, r, add, sumL, cntL);
    if (small == N)
        return solve(t->L, l, m, add, sumL, cntL);
    long long nsum = sumL + getSum(t->L);
    long long ncnt = cntL + getCnt(t->L);
    double x = (nsum + add) / ncnt;
    if (x > small)
        return solve(t->R, m + 1, r, add, nsum, ncnt);
    else
        return solve(t->L, l, m, add, sumL, cntL);
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, q;
    Node *root = NULL;
    scanf("%d%d", &n, &q);
    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        val[i] = x;
        root = add(root, 0, N, val[i], PLL(val[i], 1));
    }
    for(int i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int p, x;
            scanf("%d%d", &p, &x);
            --p;
            root = add(root, 0, N, val[p], PLL(-val[p], -1));
            val[p] = x;
            root = add(root, 0, N, val[p], PLL(val[p], 1));
        }
        else
        {
            long long add;
            scanf("%I64d", &add);
            /*cerr.setf(ios::fixed);
            cerr.precision(6);
            cerr << solve(root, 0, N, add, 0, 0) << endl;*/
            printf("%.6f\n", solve(root, 0, N, add, 0, 0));
        }
    }
    return 0;
}