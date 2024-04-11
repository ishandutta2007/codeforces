#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

bool room[11][20001];
int fb[20001];
int fbc[11];

int main()
{
    int n, m, k, me, ch, a;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> room[j][i];

    for (int x = 0; x < k; ++x)
    {
        cin >> me >> ch;
        fb[me]--;
        fbc[ch]++;
    }

    for (int i = 1; i <= n; ++i)
    {
        a = 0;
        for (int j = 1; j <= m; ++j)
            if (room[j][i])
                a += fbc[j];
        cout << a + fb[i] << ' ';
    }
    return 0;
}