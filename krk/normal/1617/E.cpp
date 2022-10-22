#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Inf = 1000000000;
const int Maxb = 32;
const int Maxn = 200005;

int n;
int a[Maxn];
vector <int> ind[Maxb];
map <int, ii> M;
ii best[Maxb];
int res = -Inf;
int ba, bb;

int getNext(int x)
{
    int b = 0;
    while (1 << b < x) b++;
    return (1 << b) - x;
}

void Check(const ii &a, const ii &b)
{
    if (a.first + b.first > res) {
        res = a.first + b.first;
        ba = a.second; bb = b.second;
    }
}

void Insert(int key, ii val)
{
    auto it = M.find(key);
    if (it == M.end()) M.insert(make_pair(key, val));
    else {
        Check(it->second, val);
        it->second = max(it->second, val);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 0) ind[0].push_back(i);
        else {
            int b = 0;
            while (!(a[i] & 1 << b)) b++;
            ind[b + 1].push_back(i);
        }
    }
    fill(best, best + Maxb, ii(-Inf, -1));
    for (int i = 0; i < Maxb; i++) if (!ind[i].empty()) {
        M.clear();
        for (int j = 0; j < ind[i].size(); j++) {
            int in = ind[i][j];
            Insert(a[in], ii(0, in));
        }
        while (!M.empty()) {
            auto it = M.end(); it--;
            if (it->first == 0) { best[i] = it->second; break; }
            int nxt = getNext(it->first);
            ii p = it->second; p.first++;
            M.erase(it++);
            Insert(nxt, p);
        }
    }
    for (int i = 0; i < Maxb; i++)
        for (int j = i + 1; j < Maxb; j++)
            Check(best[i], best[j]);
    printf("%d %d %d\n", ba, bb, res);
    return 0;
}