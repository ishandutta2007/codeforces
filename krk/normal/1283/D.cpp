#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Inf = 1000000000;

int n, m;
map <int, int> M;
vector <int> Q;
ll res;

int getDist(int x)
{
    auto it = M.find(x);
    return it == M.end()? Inf: it->second;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        M[x] = 0;
        Q.push_back(x);
    }
    for (int i = 0; i < Q.size() && Q.size() < n + m; i++) {
        int v = Q[i];
        int d = getDist(v);
        if (d + 1 < getDist(v - 1)) {
            M[v - 1] = d + 1;
            Q.push_back(v - 1);
        }
        if (d + 1 < getDist(v + 1)) {
            M[v + 1] = d + 1;
            Q.push_back(v + 1);
        }
    }
    for (int i = n; i < n + m; i++)
        res += getDist(Q[i]);
    printf("%I64d\n", res);
    for (int i = n; i < n + m; i++)
        printf("%d%c", Q[i], i + 1 < n + m? ' ': '\n');
    return 0;
}