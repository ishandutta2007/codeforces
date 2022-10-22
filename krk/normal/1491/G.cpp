#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int p[Maxn];
bool tk[Maxn];
vector <vector <int> > seq;
vector <ii> res;

void Swap(int a, int b)
{
    res.push_back(ii(a, b));
    swap(p[a], p[b]);
}

void Solve(int a, int b)
{
    while (p[a] != b)
        Swap(a, p[a]);
    while (p[b] != a)
        Swap(b, p[b]);
    Swap(a, b);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    for (int i = 1; i <= n; i++) if (!tk[i]) {
        int cur = i;
        vector <int> tmp;
        while (!tk[cur]) {
            tmp.push_back(cur);
            tk[cur] = true;
            cur = p[cur];
        }
        seq.push_back(tmp);
    }
    while (seq.size() >= 2) {
        auto a = seq.back()[0]; seq.pop_back();
        auto b = seq.back()[0]; seq.pop_back();
        Swap(a, b);
        Solve(a, b);
    }
    if (!seq.empty() && seq[0].size() > 1) {
        int sam = 1;
        while (sam <= n && p[sam] != sam) sam++;
        if (sam <= n) {
            Swap(sam, seq[0][0]);
            Solve(sam, seq[0][0]);
        } else {
            int a = seq[0][0];
            int b = p[a];
            int c = p[b];
            Swap(a, b);
            Swap(b, c);
            Solve(a, b);
        }
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}