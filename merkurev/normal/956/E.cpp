#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int N = (int) 1e4 + 100;
int a[N], b[N];

bitset <N> bad[N];

void epr(bitset <N> x)
{
    for (int i = 0; i < 10; i++)
        eprintf("%d", (int)x[i] );
    eprintf("\n");
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    int gsum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i] );
        gsum += a[i];
    }
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i] );

    r = min(r, gsum - 1);

    vector <int> agood, abad;
    for (int i = 0; i < n; i++)
        if (b[i] )
            agood.push_back(a[i] );
        else
            abad.push_back(a[i] );
    sort(agood.begin(), agood.end() );

    bad[0][0] = 1;

    int cbad = (int) abad.size(), cgood = (int) agood.size();

    for (int i = 0; i < cgood; i++)
        abad.push_back(agood[cgood - i - 1] );

    for (int i = 0; i < cbad + cgood; i++)
        bad[i + 1] = bad[i] | (bad[i] << abad[i] );
    
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < cgood; i++)
    {
        int ir = r - sum, il = l;
        if (ir < il) break;
//        eprintf("il = %d, ir = %d\n", il, ir);
        int id = cbad + cgood - i;
        if (i == cgood - 1)
            id--;
//        eprintf("id = %d\n", id);
//        epr(bad[id]);
        auto cur = (bad[id] >> il);
        cur = (cur << (N - (ir - il + 1) ) );
        if (cur.count() != 0)
            ans = i + 1;
        sum += agood[i];
    }
    printf("%d\n", ans);


	return 0;
}