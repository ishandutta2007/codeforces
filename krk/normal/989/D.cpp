#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 100005;

int n, L, M;
int neut;
vector <ii> A, B;
ll res;
vector <ll> un;
int BIT[Maxn];

int Count(const vector <ii> &V, int con)
{
    int res = 0;
    for (int i = 0; i < V.size(); i++)
        res += V[i].second == con;
    return res;
}

void Add(ll val)
{
    int ind = lower_bound(un.begin(), un.end(), val) - un.begin();
    for (int i = ind + 1; i > 0; i -= i & -i)
        BIT[i]++;
}

int Get(ll val)
{
    int res = 0;
    int ind = upper_bound(un.begin(), un.end(), val) - un.begin();
    for (int i = ind + 1; i <= un.size(); i += i & -i)
        res += BIT[i];
    return res;
}

ll Solve(vector <ii> &V)
{
    sort(V.begin(), V.end());
    un.clear();
    for (int i = 0; i < V.size(); i++) if (V[i].second == -1)
        un.push_back(ll(V[i].first + L) * (M - 1));
    sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
    fill(BIT, BIT + int(un.size()) + 1, 0);
    ll res = 0;
    for (int i = int(V.size()) - 1; i >= 0; i--)
        if (V[i].second == -1)
            Add(ll(V[i].first + L) * (M - 1));
        else res += Get(ll(V[i].first) * (M + 1));
    return res;
}

int main()
{
    scanf("%d %d %d", &n, &L, &M);
    for (int i = 0; i < n; i++) {
        int x, v; scanf("%d %d", &x, &v);
        if (x < 0 && 0 < x + L) neut = v;
        else if (x < 0) A.push_back(ii(-(x + L), -v));
        else B.push_back(ii(x, v));
    }
    if (neut == -1) res += Count(A, -1);
    else if (neut == 1) res += Count(B, -1);
    res += ll(Count(A, -1)) * Count(B, -1);
    res += Solve(A);
    res += Solve(B);
    cout << res << endl;
    return 0;
}