#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxb = 30;
const int all = (1 << Maxb) - 1;
const int Maxn = 100005;

int T;
int n;
int a[Maxn];
int b[Maxn];
map <int, ii> M;

void Add(int val, bool fir)
{
    auto it = M.find(val);
    if (it != M.end())
        if (fir) it->second.first++;
        else it->second.second++;
    else if (fir) M.insert(make_pair(val, ii(1, 0)));
         else M.insert(make_pair(val, ii(0, 1)));
}

bool Check()
{
    for (auto p: M)
        if (p.second.first != p.second.second)
            return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        int cur = 0;
        for (int i = Maxb - 1; i >= 0; i--) {
            M.clear();
            cur ^= 1 << i;
            for (int j = 0; j < n; j++) {
                Add((a[j] & cur), true);
                Add(((b[j] ^ all) & cur), false);
            }
            if (!Check()) cur ^= 1 << i;
        }
        printf("%d\n", cur);
    }
    return 0;
}