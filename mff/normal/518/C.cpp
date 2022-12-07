#include <iostream>

using namespace std;

typedef long long int64;

const int MAXN = (int)1e5 + 10;

int POS[MAXN];
int OBJ[MAXN];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int64 ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int v;
        cin >> v;
        OBJ[v] = i;
        POS[i] = v;
    }
    while (m--)
    {
        int v;
        cin >> v;
        ans += (OBJ[v] - 1) / k + 1;

        if (OBJ[v] == 1) continue;

        int p1 = OBJ[v];
        int other = POS[ p1 - 1 ];

        OBJ[v] = p1 - 1;
        OBJ[other] = p1;
        POS[p1 - 1] = v;
        POS[p1] = other;
    }
    cout << ans << endl;
}