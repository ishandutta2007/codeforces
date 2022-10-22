#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxl = 26;

typedef struct node* pnode;
struct node {
    pnode ch[Maxl];
    bool en;
    ll sum;
    node() {
        for (int i = 0; i < Maxl; i++)
            ch[i] = nullptr;
        sum = 0;
    }
};

int n;
int c[Maxn];
char str[Maxn];
vector <int> neigh[Maxn];
pnode my[Maxn];
ll mx = -1;
int cnt;

ll getSum(pnode tr) { return tr? tr->sum: 0; }

void Union(pnode &tr, pnode a, pnode b)
{
    if (!a || !b) tr = a? a: b;
    else {
        tr = a;
        tr->sum = 1;
        for (int i = 0; i < Maxl; i++) {
            Union(tr->ch[i], tr->ch[i], b->ch[i]);
            tr->sum += getSum(tr->ch[i]);
        }
    }
}

void Traverse(int v, int p = 0)
{
    pnode cur = nullptr;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        Union(cur, cur, my[u]);
    }
    my[v] = new node();
    my[v]->ch[str[v] - 'a'] = new node();
    my[v]->ch[str[v] - 'a']->sum = 1;
    Union(my[v]->ch[str[v] - 'a'], my[v]->ch[str[v] - 'a'], cur);
    my[v]->sum = getSum(my[v]->ch[str[v] - 'a']);
    ll cand = getSum(my[v]) + c[v];
    if (cand > mx) { mx = cand; cnt = 0; }
    if (cand == mx) cnt++;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    scanf("%s", str + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    Traverse(1);
    cout << mx << endl;
    cout << cnt << endl;
    return 0;
}