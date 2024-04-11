#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

struct hero
{
    int hp, atk, def;
    hero() 
    {
        hp = atk = def = 0;
    }
};

bool solve()
{
    hero y, m;

    cin >> y.hp >> y.atk >> y.def;
    cin >> m.hp >> m.atk >> m.def;

    int h, a, d;

    cin >> h >> a >> d;

    int ans = -1, tmp, t1, t2;
    bool f = 1;
    for(int hp(y.hp);hp <= 1000;hp++)
    {
        for(int atk(y.atk);atk <= 200;atk++)
        {
            for(int def(y.def);def <= 200;def++)
            {
                if(max(0, atk - m.def) == 0) continue;
                if(max(0, m.atk - def) > 0)
                {
                    t1 =  m.hp / max(0, atk - m.def) + (m.hp % max(0, atk - m.def) != 0); // - m
                    t2 =  hp / max(0, m.atk - def) + (hp % max(0, m.atk - def) != 0); // - y

                    if(t1 < t2 && (ans == -1 || ans > (hp - y.hp) * h + (atk - y.atk) * a + (def - y.def) * d))
                        ans = (hp - y.hp) * h + (atk - y.atk) * a + (def - y.def) * d;
                }else
                    if(ans == -1 || ans > (hp - y.hp) * h + (atk - y.atk) * a + (def - y.def) * d)
                        ans = (hp - y.hp) * h + (atk - y.atk) * a + (def - y.def) * d;
            }
        }
    }

    cout << max(ans, 0) << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}