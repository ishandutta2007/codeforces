#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

struct edge {
    int b;
    int wh;
    int ind1, ind2;
    int eind;
    edge(int b = 0, int wh = 0, int ind1 = 0, int ind2 = 0, int eind = 0): b(b), wh(wh), ind1(ind1), ind2(ind2), eind(eind) {}
};

int m;
vector <int> arr[Maxn];
string res[Maxn];
vector <int> un;
int cur[Maxn];
vector <edge> neigh[Maxn];
int pnt;
bool tk[Maxn];

void Traverse(int v)
{
    while (!neigh[v].empty())
        if (tk[neigh[v].back().eind]) neigh[v].pop_back();
        else {
            tk[neigh[v].back().eind] = true;
            res[neigh[v].back().wh][neigh[v].back().ind1] = 'L';
            res[neigh[v].back().wh][neigh[v].back().ind2] = 'R';
            Traverse(neigh[v].back().b);
        }
}

int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int siz; scanf("%d", &siz);
        arr[i].resize(siz);
        for (int j = 0; j < arr[i].size(); j++) {
            scanf("%d", &arr[i][j]);
            un.push_back(arr[i][j]);
        }
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    fill(cur, cur + Maxn, -1);
    for (int i = 0; i < m; i++) {
        res[i].resize(arr[i].size());
        for (int j = 0; j < arr[i].size(); j++) {
            arr[i][j] = lower_bound(un.begin(), un.end(), arr[i][j]) - un.begin();
            int num = arr[i][j];
            if (cur[num] != -1) {
                res[i][cur[num]] = 'L';
                res[i][j] = 'R';
                cur[num] = -1;
            } else cur[num] = j;
        }
        int lst = -1;
        for (int j = 0; j < arr[i].size(); j++) {
            int num = arr[i][j];
            if (cur[num] != -1) {
                if (lst != -1) {
                    neigh[arr[i][lst]].push_back(edge(num, i, lst, cur[num], pnt));
                    neigh[num].push_back(edge(arr[i][lst], i, cur[num], lst, pnt));
                    pnt++;
                    lst = -1;
                } else lst = cur[num];
                cur[num] = -1;
            }
        }
    }
    for (int i = 0; i < Maxn; i++)
        if (neigh[i].size() % 2) { printf("NO\n"); return 0; }
    for (int i = 0; i < Maxn; i++)
        if (!neigh[i].empty()) Traverse(i);
    printf("YES\n");
    for (int i = 0; i < m; i++)
        printf("%s\n", res[i].c_str());
    return 0;
}