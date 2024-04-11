#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int X[Maxn], Y[Maxn];
map <int, vector <int> > M;
bool has[Maxn];
vector <int> un;
int BIT[Maxn];
ll res;

void Update(int x)
{
    x++;
    for (int i = x; i < Maxn; i += i & -i)
        BIT[i]++;
}

int Get(int x)
{
    x++;
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

ll Process(vector <int> &V)
{
    sort(V.begin(), V.end());
    int lef, rig;
    rig = lower_bound(un.begin(), un.end(), V[0]) - un.begin() - 1;
    int siz = Get(rig);
    ll bad = ll(siz) * (siz + 1) / 2;
    for (int i = 0; i + 1 < V.size(); i++) if (V[i] + 1 < V[i + 1]) {
        lef = upper_bound(un.begin(), un.end(), V[i]) - un.begin() - 1;
        rig = lower_bound(un.begin(), un.end(), V[i + 1]) - un.begin() - 1;
        siz = Get(rig) - Get(lef);
        bad += ll(siz) * (siz + 1) / 2;
    }
    lef = upper_bound(un.begin(), un.end(), V.back()) - un.begin() - 1;
    siz = Get(Maxn - 2) - Get(lef);
    bad += ll(siz) * (siz + 1) / 2;
    for (int i = 0; i < V.size(); i++) {
        int ind = lower_bound(un.begin(), un.end(), V[i]) - un.begin();
        if (!has[ind]) {
            has[ind] = true;
            Update(ind);
        }
    }
    siz = Get(Maxn - 2);
    return ll(siz) * (siz + 1) / 2 - bad;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        un.push_back(X[i]);
        M[Y[i]].push_back(X[i]);
    }
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    for (map <int, vector <int> >::reverse_iterator it = M.rbegin(); it != M.rend(); it++)
        res += Process(it->second);
    printf("%I64d\n", res);
    return 0;
}