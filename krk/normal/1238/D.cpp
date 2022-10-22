#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int n;
char str[Maxn];
vector <int> V[2];
ll res;

int main()
{
    scanf("%d", &n);
    scanf("%s", str + 1);
    V[0].push_back(0);
    V[1].push_back(0);
    for (int i = 1; i <= n; i++)
        V[str[i] - 'A'].push_back(i);
    V[0].push_back(n + 1);
    V[1].push_back(n + 1);
    res = ll(n) * (n + 1) / 2;
    for (int i = 0; i < 2; i++)
        for (int j = 1; j + 1 < V[i].size(); j++) {
            res -= (V[i][j] - V[i][j - 1]);
            res -= (V[i][j + 1] - V[i][j]);
            res++;
        }
    for (int i = 1; i + 1 <= n; i++)
        if (str[i] == 'A' && str[i + 1] == 'B' ||
            str[i] == 'B' && str[i + 1] == 'A')
            res++;
    cout << res << endl;
    return 0;
}