#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>


using namespace std;

typedef long long ll;
typedef long double ld;


char arr[1200][1200];

int n, m;

int tt[1200];
int ntt[1200];


int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf(" %c", &arr[i][j]);
        }
    }

    int cnt = 0;
    for (int j = 0; j < m; ++j)
    {
        bool fl = false;
        for (int i = 0; i < n - 1; ++i)
            if (arr[i][j] > arr[i + 1][j] && tt[i] == tt[i + 1])
            {
                fl = true;
                ++cnt;
                break;
            }
        if (fl)
            continue;

        ntt[0] = 0;
        for (int i = 1; i < n; ++i)
            if (tt[i] == tt[i - 1] && arr[i][j] == arr[i - 1][j])
                ntt[i] = ntt[i - 1];
            else
                ntt[i] = ntt[i - 1] + 1;
        memcpy(tt, ntt, sizeof(ntt[0]) * n);
    }

    cout << cnt;


    return 0;
}