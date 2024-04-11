#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, m;

pair <int, int> a[nax];
int w[nax];
int f[nax];
vector <int> naive[nax];
bool vis[nax];


int main ()
{
    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= n ; ++ i)
    {
        scanf("%d", w + i);
        f[i] = w[i];
    }

    for (int i = 1 ; i <= m ; ++ i)
    {
        scanf("%d %d", &a[i].first, &a[i].second);
    }


    for (int i = 1 ; i <= m;  ++ i)
    {
        -- f[a[i].first];
        -- f[a[i].second];
    }

    vector <int> setik;
    setik.reserve(m);
    #define insert push_back

    for (int i = 1 ; i <= m ; ++ i) {
        if (max(f[a[i].first], f[a[i].second]) >= 0) {
            setik.insert(i);
            vis[i] = true;
        }
        else {
            naive[a[i].first].insert(i);
            naive[a[i].second].insert(i);
        }
    }

    vector <int> ans;

    while (!setik.empty()) {
        int v = setik.back();
        setik.pop_back();
        auto [x,y] = a[v];
        ans.push_back(v);
        ++ f[x];
        ++ f[y];

        if (f[x] >= 0)  {
            for (int i : naive[x]) {
                if (!vis[i])
                    setik.insert(i);
                vis[i] = true;
            }
        }

        if (f[y] >= 0) {
            for (int i : naive[y]) {
                if (!vis[i])
                    setik.insert(i);
                vis[i] = true;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    if ((int)ans.size() != m) return !printf("DEAD");
    puts("ALIVE");

    for (int i : ans)
        printf("%d ", i);
    printf("\n");

}
/*
    Leon is the best girl in A17.
*/