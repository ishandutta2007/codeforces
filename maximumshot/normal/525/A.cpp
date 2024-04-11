#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
  
using namespace std;
  
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair 
#define vec vector
#define go(x, y) q.push(mp((x), (y))), ans[(x)][(y)] = 1;
  
typedef long long LL;
typedef long double LD;
  
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf * 10000 + 7; 
const LL p = 239017;

bool solve()
{
    int n, ans = 0;
    string a;

    cin >> n >> a;

    vec<int> c1, c2;
    c1 = c2 = vec<int>(26, 0);

    for(int i(0);i < 2 * n - 2;i++)
    {
        if(i % 2 == 0) c1[a[i] - 'a']++;
        else
        {
            if(c1[a[i] - 'A'] > 0) c1[a[i] - 'A']--;
            else ans++;
        }
    }

    cout << ans << '\n';

    return true;    
}
  
int main()
{
    //while(solve());
    solve();
  
    return 0;
}