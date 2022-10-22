#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
int p[Maxn];
map <int, int> M;
ll res;

int Get(int x)
{
    map <int, int>::iterator it = M.find(x);
    return it == M.end()? 0: it->second;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    int pnt = 1;
    while (p[pnt] != m) pnt++;
    int cur = 0; M[0]++;
    for (int i = pnt - 1; i > 0; i--) {
        if (p[i] > m) cur++;
        else cur--;
        M[cur]++;
    }
    cur = 0; res += Get(-cur) + Get(-cur + 1);
    for (int i = pnt + 1; i <= n; i++) {
        if (p[i] > m) cur++;
        else cur--;
        res += Get(-cur) + Get(-cur + 1);
    }
    cout << res << endl;
    return 0;
}