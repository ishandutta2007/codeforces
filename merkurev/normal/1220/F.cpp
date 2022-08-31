#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif


const int LOG = 19;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);

struct Tree
{
    int mn[SZ], mx[SZ], add[SZ];

    Tree() : mn(), mx(), add() {}

    void push(int v, int val)
    {
        mn[v] += val;
        mx[v] += val;
        add[v] += val;
    }
    void push(int v)
    {
        if (add[v] == 0) return;
        push(2 * v, add[v]);
        push(2 * v + 1, add[v]);
        add[v] = 0;
    }
    void update(int v)
    {
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
    void addVal(int v, int tl, int tr, int l, int r, int x)
    {
        if (r < tl || tr < l)
            return;
        if (l <= tl && tr <= r)
        {
            push(v, x);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        addVal(2 * v, tl, tm, l, r, x);
        addVal(2 * v + 1, tm + 1, tr, l, r, x);
        update(v);
    }
    void addVal(int l, int r, int x)
    {
        //eprintf("add val [%d, %d] : %d\n", l, r, x);
        addVal(1, 0, LEVEL - 1, l, r, x);
    }
    int getMin(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || tr < l)
            return SZ;
        if (l <= tl && tr <= r)
            return mn[v];
        push(v);
        int tm = (tl + tr) / 2;
        int ans = min(
                getMin(2 * v, tl, tm, l, r),
                getMin(2 * v + 1, tm + 1, tr, l, r));
        return ans;
    }
    int getMin(int l, int r)
    {
        return getMin(1, 0, LEVEL - 1, l, r);
    }
    int getMax(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || tr < l)
            return 0;
        if (l <= tl && tr <= r)
            return mx[v];
        push(v);
        int tm = (tl + tr) / 2;
        int ans = max(
                getMax(2 * v, tl, tm, l, r),
                getMax(2 * v + 1, tm + 1, tr, l, r));
        return ans;
    }
    int getMax(int l, int r)
    {
        return getMax(1, 0, LEVEL - 1, l, r);
    }
} tree;

const int N = (int) 4e5 + 100;
int a[N];
int prvSmaller[N], nxSmaller[N];

int segL = 0, segR = -1;

void addToSeg(int pos)
{
    if (pos != segR + 1) throw;
    int par = prvSmaller[pos];
    if (par < segL)
        par = segL - 1;
    //eprintf("par = %d, pos = %d\n", par, pos);
    int curVal = 1;
    if (par >= segL)
        curVal = tree.getMin(par, par) + 1;
    //eprintf("curVal = %d\n", curVal);
    tree.addVal(par + 1, segR, 1);
    tree.addVal(pos, pos, curVal);

    segR++;
}

void delFromSeg(int pos)
{
    if (pos != segL) throw;
    int nx = nxSmaller[pos];
    if (nx > segR)
        nx = segR + 1;
    tree.addVal(segL + 1, nx - 1, -1);
    
    segL++;
}

int getMaxOnSeg()
{
    return tree.getMax(segL, segR);
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[n + i] = a[i];
    }
    vector <int> st;
    for (int i = 0; i < 2 * n; i++)
    {
        while (!st.empty() && a[st.back()] >= a[i])
            st.pop_back();
        if (st.empty())
            prvSmaller[i] = -1;
        else
            prvSmaller[i] = st.back();
        st.push_back(i);
    }
    st.clear();
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && a[st.back()] >= a[i])
            st.pop_back();
        if (st.empty())
            nxSmaller[i] = 2 * n;
        else
            nxSmaller[i] = st.back();
        st.push_back(i);
    }
    st.clear();

    for (int i = 0; i < n; i++)
    {
        //eprintf("add to seg %d\n", i);
        addToSeg(i);
    }
    int mn = n + 1, mnpos = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = getMaxOnSeg();
        if (cur < mn)
        {
            mn = cur;
            mnpos = i;
        }
        delFromSeg(i);
        addToSeg(i + n);
    }
    printf("%d %d\n", mn, mnpos);

    return 0;
}