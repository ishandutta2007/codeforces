#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 800005;
const int Maxm = 4194304;

int n;
iii A[Maxn];
vector <int> un;
int st[2][Maxm], fl[2][Maxm];

void downOn(int t, int v, int f)
{
    st[t][v] += f;
    fl[t][v] += f;
}

void Down(int t, int v)
{
    if (fl[t][v]) {
        downOn(t, 2 * v, fl[t][v]);
        downOn(t, 2 * v + 1, fl[t][v]);
        fl[t][v] = 0;
    }
}

void Union(int t, int v)
{
    st[t][v] = max(st[t][2 * v], st[t][2 * v + 1]);
}

void Add(int t, int v, int l, int r, int a, int b)
{
    if (l == a && r == b) downOn(t, v, 1);
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (a <= m) Add(t, 2 * v, l, m, a, min(m, b));
        if (m + 1 <= b) Add(t, 2 * v + 1, m + 1, r, max(m + 1, a), b);
        Union(t, v);
    }
}

void Insert(int t, int v, int l, int r, int x, int val)
{
    if (l == r) st[t][v] = max(st[t][v], val);
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (x <= m) Insert(t, 2 * v, l, m, x, val);
        else Insert(t, 2 * v + 1, m + 1, r, x, val);
        Union(t, v);
    }
}

int Get(int t, int v, int l, int r, int a, int b)
{
    if (l == a && r == b) return st[t][v];
    else {
        Down(t, v);
        int m = l + r >> 1;
        if (b <= m) return Get(t, 2 * v, l, m, a, b);
        if (m + 1 <= a) return Get(t, 2 * v + 1, m + 1, r, a, b);
        return max(Get(t, 2 * v, l, m, a, m), Get(t, 2 * v + 1, m + 1, r, m + 1, b));
    }
}

bool Less(const iii &a, const iii &b)
{
    return a.first.second < b.first.second;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &A[i].first.first, &A[i].first.second, &A[i].second);
        A[i].second--;
        un.push_back(A[i].first.first);
        un.push_back(A[i].first.second);
    }
    un.push_back(1000000007);
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    sort(A, A + n, Less);
    for (int i = 0; i < n; i++) {
        int t = A[i].second;
        int lef = lower_bound(un.begin(), un.end(), A[i].first.first) - un.begin();
        int rig = upper_bound(un.begin(), un.end(), A[i].first.second) - un.begin();
        Add(t, 1, 0, int(un.size()) - 1, 0, lef);
        int cur = Get(t, 1, 0, int(un.size()) - 1, 0, lef);
        Insert(1 - t, 1, 0, int(un.size()) - 1, rig, cur);
    }
    printf("%d\n", max(st[0][1], st[1][1]));
    return 0;
}