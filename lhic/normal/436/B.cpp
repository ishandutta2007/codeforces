#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAX_N = 100000;

int n, m;

int k;

int arr[3000];

int main()
{
    //ios_base::sync_with_stdio(false);

    scanf("%d %d %d ",&n,&m,&k);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c;
            scanf("%c ",&c);
            if (c == '.')
                continue;
            if (c == 'D')
                continue;
            if (c == 'U')
            {
                if (i % 2 == 0)
                    ++arr[j];
            }
            if (c == 'L')
            {
                if (j - i >= 0)
                    ++arr[j - i];
            }
            if (c == 'R')
            {
                if (j + i < m)
                    ++arr[i + j];
            }

        }
    }

    for (int i = 0; i < m; ++i)
        printf("%d ",arr[i]);


    return 0;
}