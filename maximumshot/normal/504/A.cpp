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

#include <conio.h>

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

int Abs (int x) {return (x >= 0?x : -x);}

const LL p = 157;

bool solve()
{   
    int n;

    scanf("%d", &n);

    vec< pair<int, int> > v(n);

    for(int i(0);i < n;i++) scanf("%d %d", &v[i].first, &v[i].second);
    
    queue<int> q;

    for(int i(0);i < n;i++)
        if(v[i].first == 1) 
            q.push(i);

    vec< pair<int, int> > ans;

    while(!q.empty())
    {
        int p = q.front();
        q.pop();

        //cout << p << '\n';

        if(v[p].first != 1) continue;

        v[p].first--;
        ans.push_back(mp(p, v[p].second));
        v[v[p].second].first--;
        v[v[p].second].second ^= p;

        if(v[v[p].second].first == 1) q.push(v[p].second);
    }

    printf("%d\n", (int)ans.size());
    
    for(int i(0);i < (int)ans.size();i++) printf("%d %d\n", ans[i].first, ans[i].second);

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}