#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = (1ll << 62);    
const double pi = acos(-1.0);

using namespace std;

LL Abs (LL x) {return (x >= 0ll?x : -x);}

bool solve()
{
    int n, k;

    cin >> n >> k;

    vec< pair<int, int> >  a(n);
    vec<vec<int>> mat(n, vec<int>(k + 1, 0));

    for(int i(0);i < n;i++) cin >> a[i].first, a[i].second = i;

    sort(ALL(a));

    vec<bool> used(k + 1);

    mat[a[0].second][1] = a[0].first;

    for(int i(1);i < n;i++) 
    {
        mat[a[i].second] = mat[a[i - 1].second];
        int cnt = a[i].first - a[i - 1].first;
        if(cnt == 0) continue;

        int c = 0, last = -1;

        for(int j(1);j <= k;j++) 
        {
            if(mat[a[i].second][j] > 0)
                c++;
            else if(last == -1) last = j;
        }

        //cout << a[i].second << ' ' << last << ' ' << c << '\n';

        if(cnt > k) 
        {
            puts("NO");
            return true;
        }
        int q = 0;
        for(int j(1);j <= k && q < cnt;j++)
        {
            if(used[j]) continue;
            q++;
            used[j] = 1;
            mat[a[i].second][j]++;
        }

        if(q < cnt) {puts("NO"); return true;}
        
    }

    puts("YES");

    for(int i(0);i < n;i++)
    {
        for(int j(1);j <= k;j++)
            for(int z(0);z < mat[i][j];z++) cout << j << ' ';
        cout << '\n';
    }

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}