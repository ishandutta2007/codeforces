#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;

const int Maxn = 600006;

int n;
int sam[Maxn];
map <int, int> neigh[Maxn];
int cur, tk[Maxn];
vector <ii> B;
vector <string> res1, res2;

ii Swap(const ii &a) { return ii(a.second, a.first); }

void writeTwo(ii a, ii b)
{
    if (a.first != b.first) a = Swap(a);
    B.push_back(a);
    B.push_back(Swap(b));
    res1.push_back("LR");
    res1.push_back("LR");
    res2.push_back("UU");
    res2.push_back("DD");
}

void writeThree(ii a, ii b, ii c)
{
    if (a.first == b.first && a.first == c.first) {
        B.push_back(a);
        B.push_back(Swap(b));
        B.push_back(c);
    } else {
        B.push_back(Swap(a));
        B.push_back(b);
        B.push_back(c);
    }
    res1.push_back("UU");
    res1.push_back("DD");
    res1.push_back("LR");
    res2.push_back("LR");
    res2.push_back("UU");
    res2.push_back("DD");
}

int approxDegree(int v)
{
    if (neigh[v].empty()) return sam[v];
    if (neigh[v].size() >= 2) return 2;
    return neigh[v].begin()->second + sam[v];
}

void addTraverse(vector <ii> &V1, ii p)
{
    if (!V1.empty()) {
        writeTwo(V1.back(), p);
        V1.pop_back();
    } else V1.push_back(p);
}

ii Traverse(int v)
{
    tk[v] = ++cur;
    vector <ii> V;
    for (int i = 0; i < sam[v]; i++)
        addTraverse(V, ii(v, v));
    for (auto u: neigh[v]) {
        if (tk[u.first] && tk[u.first] < tk[v]) continue;
        int lft = u.second;
        ii got = tk[u.first]? ii(-1, -1): Traverse(u.first);
        if (got.first != -1) {
            writeTwo(ii(v, u.first), got);
            lft--;
        }
        while (lft--)
            addTraverse(V, ii(v, u.first));
    }
    return V.empty()? ii(-1, -1): V[0];
}

void addRoot(vector <ii> &V1, vector <iiii> &V2, ii p)
{
    if (!V1.empty() && (V1.size() >= 3 || !V2.empty())) {
        writeTwo(V1.back(), p);
        V1.pop_back();
    } else V1.push_back(p);
}

void addRoot(vector <ii> &V1, vector <iiii> &V2, iiii p)
{
    if (V1.size() >= 2 || !V2.empty())
        writeTwo(p.first, p.second);
    else V2.push_back(p);
}

void Root(int v)
{
    tk[v] = ++cur;
    vector <ii> V1;
    vector <iiii> V2;
    for (int i = 0; i < sam[v]; i++)
        addRoot(V1, V2, ii(v, v));
    for (auto u: neigh[v]) {
        if (tk[u.first] && tk[u.first] < tk[v]) continue;
        int lft = u.second;
        ii got = tk[u.first]? ii(-1, -1): Traverse(u.first);
        if (got.first != -1) {
            addRoot(V1, V2, iiii(ii(v, u.first), got));
            lft--;
        }
        while (lft--)
            addRoot(V1, V2, ii(v, u.first));
    }
    if (V2.empty())
        if (V1.size() == 2) writeTwo(V1[0], V1[1]);
        else writeThree(V1[0], V1[1], V1[2]);
    else if (V1.empty()) writeTwo(V2[0].first, V2[0].second);
         else writeThree(V1[0], V2[0].first, V2[0].second);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a == b) sam[a]++;
        else {
            neigh[a][b]++;
            neigh[b][a]++;
        }
    }
    for (int i = 0; i < Maxn; i++) if (!tk[i])
        if (approxDegree(i) >= 2)
            Root(i);
    for (int i = 0; i < Maxn; i++) if (!tk[i])
        if (approxDegree(i) > 0) {
            printf("-1\n");
            return 0;
        }
    printf("%d %d\n", int(B.size()), 2);
    printf("\n");
    for (int i = 0; i < B.size(); i++)
        printf("%d %d\n", B[i].first, B[i].second);
    printf("\n");
    for (int i = 0; i < res1.size(); i++)
        printf("%s\n", res1[i].c_str());
    printf("\n");
    for (int i = 0; i < res2.size(); i++)
        printf("%s\n", res2[i].c_str());
    return 0;
}