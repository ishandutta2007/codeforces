#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

set<pair<int, int> > kv;
set<pair<int, int> > romb;

int main()
{
    //freopen("input.txt", "r", stdin);
    pair<int,int> pk[4];
    pair<int,int> pr[4];
    pair<int, int> ll = {200, 200}, ur = {-200, -200};
    for (int i = 0; i < 4; ++i) {
        cin >> pk[i].F >> pk[i].S;
    }
    sort(pk, pk + 4);
    ll = pk[0];
    ur = pk[3];
    for (int x = ll.F; x <= ur.F; ++x) {
        for (int y = ll.S; y <= ur.S; ++y) {
            kv.insert(MP(x, y));
            //cout << x << ' ' << y << endl;
        }
    }


    for (int i = 0; i < 4; ++i) {
        cin >> pr[i].F >> pr[i].S;
    }
    pair<int, int> t, b, l, r;
    sort(pr, pr + 4);
    b = pr[1];
    t = pr[2];
    l = pr[0];
    r = pr[3];
    int delta = 1;
    int xl = b.F;
    int xr = b.F;
    //cout << "==" << endl;
    for (int y = b.S; y <= t.S; ++y) {
        for (int x = xl; x <= xr; ++x) {
            romb.insert(MP(x, y));
            //cout << x << ' ' << y << endl;
        }
        if (xl == l.F && xr == r.F) {
            delta = -1;
        }
        xl -=delta;
        xr += delta;
    }
    for (int x = -101; x <= 101; ++x) {
        for (int y = -101; y <= 101; ++y) {
            pair<int, int> a = MP(x,y);
            if (kv.count(a) && romb.count(a)) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}