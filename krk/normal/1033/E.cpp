#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 606;

int n;
int par[Maxn], odd[Maxn], siz[Maxn], super[Maxn];
vector <int> neigh[Maxn];
vector <int> ans1;
bool tk[Maxn];

bool Get(int a, int b)
{
    if (tk[a]) return false;
    tk[a] = true;
    if (a == b) { ans1.push_back(b); return true; }
    for (int i = 0; i < neigh[a].size(); i++) {
        int u = neigh[a][i];
        if (Get(u, b)) { ans1.push_back(a); return true; }
    }
    return false;
}

ii getPar(int x)
{
    if (par[x] == x) return ii(x, odd[x]);
    ii g = getPar(par[x]);
    par[x] = g.first; odd[x] ^= g.second;
    return ii(par[x], odd[x]);
}

int Ask(const vector <int> &V)
{
    if (V.empty()) return 0;
    printf("? %d\n", int(V.size()));
    for (int i = 0; i < V.size(); i++)
        printf("%d%c", V[i], i + 1 < V.size()? ' ': '\n');
    fflush(stdout);
    int got; scanf("%d", &got);
    return got;
}

void unionSet(int a, int b)
{
    ii para = getPar(a), parb = getPar(b);
    if (siz[para.first] < siz[parb.first]) swap(para, parb);
    par[parb.first] = para.first;
    odd[parb.first] = (para.second ^ parb.second ^ 1);
    siz[para.first] += siz[parb.first];
    vector <int> tmp;
    for (int i = 1; i <= n; i++)
        if (getPar(i).first == para.first) tmp.push_back(i);
    super[para.first] = Ask(tmp);
}

int Check(int mid, int ind)
{
    int ans = 0;
    vector <int> my; my.push_back(ind);
    for (int i = 1; i <= n; i++)
        if (1 <= getPar(i).first && getPar(i).first <= mid &&
            getPar(i).first != getPar(ind).first)
            my.push_back(i);
    for (int i = 1; i <= mid; i++) if (getPar(i).first == i && i != getPar(ind).first)
        ans -= super[i];
    ans += Ask(my);
    return ans;
}

int Get(int comp, int flag, int ind)
{
    vector <int> V;
    for (int i = 1; i <= n; i++)
        if (getPar(i).first == comp && getPar(i).second == flag)
            V.push_back(i);
    V.push_back(ind);
    if (Ask(V) == 0) return -1;
    V.pop_back();
    int lef = 0, rig = int(V.size()) - 1;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        vector <int> tmp;
        for (int i = 0; i <= mid; i++)
            tmp.push_back(V[i]);
        tmp.push_back(ind);
        if (Ask(tmp) > 0) rig = mid - 1;
        else lef = mid + 1;
    }
    rig++;
    return V[rig];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        par[i] = i, odd[i] = 0, siz[i] = 1;
        while (Check(i - 1, i)) {
            int lef = 1, rig = i - 1;
            while (lef <= rig) {
                int mid = lef + rig >> 1;
                if (Check(mid, i)) rig = mid - 1;
                else lef = mid + 1;
            }
            int jon = rig + 1;
            int a = Get(jon, 0, i), b = Get(jon, 1, i);
            assert(a > 0 || b > 0);
            if (a > 0 && b > 0) {
                Get(a, b);
                ans1.push_back(i);
                printf("N %d\n", int(ans1.size()));
                for (int z = 0; z < ans1.size(); z++)
                    printf("%d%c", ans1[z], z + 1 < ans1.size()? ' ': '\n');
                fflush(stdout); return 0;
            }
            if (a <= 0) a = b;
            unionSet(a, i);
            neigh[a].push_back(i);
            neigh[i].push_back(a);
        }
    }
    for (int i = 1; i <= n; i++)
        if (getPar(i).second == 0) ans1.push_back(i);
    printf("Y %d\n", int(ans1.size()));
    for (int i = 0; i < ans1.size(); i++)
        printf("%d%c", ans1[i], i + 1 < ans1.size()? ' ': '\n');
    fflush(stdout);
    return 0;
}