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

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;

bool solve()
{
    LL w, h, n, x, y;
    char type;

    scanf("%I64d %I64d %I64d", &w, &h, &n);

    vec<LL> lenw(w + 2, -inf64);
    vec<LL> lenh(h + 2, -inf64);

    set< LL > crdw, crdh;
    set< pair<LL, LL> > answ, ansh;

    crdw.insert(0);
    crdw.insert(w);
    crdh.insert(0);
    crdh.insert(h);

    answ.insert(mp(w, 0)); lenw[0] = w;
    for(int i(1);i <= w;i++) answ.insert(mp(-inf64, i));
    ansh.insert(mp(h, 0)); lenh[0] = h;
    for(int i(1);i <= h;i++) ansh.insert(mp(-inf64, i));

    for(int i(0);i < n;i++)
    {
        scanf(" %c", &type);

        if(type == 'H')
        {
            scanf("%I64d", &y);
            set<LL>::iterator fnd = crdh.lower_bound(y);
            fnd--;
            
            ansh.erase(mp(lenh[*fnd], *fnd));

            lenh[y] = lenh[*fnd] - (y - *fnd);
            lenh[*fnd] = y - *fnd;

            ansh.insert(mp(lenh[*fnd], *fnd));
            ansh.insert(mp(lenh[y], y));

            crdh.insert(y);
        }else
        {
            scanf("%I64d", &x);
            set<LL>::iterator fnd = crdw.lower_bound(x);
            fnd--;

            answ.erase(mp(lenw[*fnd], *fnd));

            lenw[x] = lenw[*fnd] - (x - *fnd);
            lenw[*fnd] = x - *fnd;

            answ.insert(mp(lenw[*fnd], *fnd));
            answ.insert(mp(lenw[x], x));

            crdw.insert(x);
        }

        LL A, B;
        A = (--answ.end())->first;
        B = (--ansh.end())->first;

        printf("%I64d\n", A * B);
    }

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}