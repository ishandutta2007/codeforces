#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <time.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf * 1000ll + 17;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

template<typename T, typename P>
const ostream & operator << (ostream & os, const pair<T, P> & a) {
    os.precision(10);
    os << fixed;
    os << a.first;
    os << ' ';
    os << a.second;
    os << '\n';
    return os;
}

LL gcd(LL x, LL y) { 
    return (x == 0?y : gcd(y % x, x));
}

LL sq(LL x) {
    LL bl, br, bm;
    bl = 0, br = inf;
    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(bm * (bm - 1) <= 2ll * x) bl = bm;
        else br = bm - 1;
    }

    return (br * (br - 1) == 2ll * x?br : bl);
}

LL slow(const vec< pair<LL, LL> > crd) {
    LL ans = 0;
    LL n = (int)crd.size();
    for(int i(0);i < n;i++) {
        for(int j(i + 1);j < n;j++) {
            for(int z(j + 1);z < n;z++) {
                LL x1, y1, x2, y2, x3, y3;
            }
        }
    }
    return 0;
}

bool solve()
{
    LL n;
    cin >> n;

    vec< pair<LL, LL> > crd;

    for(int i(0);i < n;i++) {
        LL x, y;
        cin >> x >> y;
        crd.push_back(mp(x, y));
    }

    vec< pair< pair<LL, LL>, pair<LL, LL> > > mas;
    vec< LL > hor, ver; 

    for(int i(0);i < n;i++) {
        for(int j(i + 1);j < n;j++) {
            pair< LL, LL > k, b;
            LL num, den;
            LL x1, y1, x2, y2, g;
            x1 = crd[i].first, y1 = crd[i].second;
            x2 = crd[j].first, y2 = crd[j].second;

            if(x1 == x2) {
                ver.push_back(x1);
                continue;
            }

            if(y1 == y2) {
                hor.push_back(y1);
                continue;
            }

            num = y2 - y1;
            den = x2 - x1;
            g = gcd(num >= 0?num : -num, den >= 0?den : -den);
            num /= g, den /= g;
            if(den < 0) den *= -1, num *= -1;       
            
            k = mp(num, den);

            num = y1 * (x2 - x1) - x1 * (y2 - y1);
            den = x2 - x1;

            g = gcd(num >= 0?num : -num, den >= 0?den : -den);
            num /= g, den /= g;
            if(den < 0) den *= -1, num *= -1;

            b = mp(num, den);

            mas.push_back(mp(k, b));
        }
    }

    LL ans = 0;

    sort(ALL(mas));
    sort(ALL(hor));
    sort(ALL(ver));

    for(int i(0);i < (int)mas.size();i++) {
        int j = i;
        while(j < (int)mas.size() && mas[i] == mas[j]) j++; j--;
        LL cnt = j - i + 1;
        cnt = sq(cnt);
        ans -= cnt * (cnt - 1) * (cnt - 2) / 6ll;
        i = j;
    }

    for(int i(0);i < (int)hor.size();i++) {
        int j = i;
        while(j < (int)hor.size() && hor[i] == hor[j]) j++; j--;
        LL cnt = j - i + 1;
        cnt = sq(cnt);
        ans -= cnt * (cnt - 1) * (cnt - 2) / 6ll;
        i = j;
    }

    for(int i(0);i < (int)ver.size();i++) {
        int j = i;
        while(j < (int)ver.size() && ver[i] == ver[j]) j++; j--;
        LL cnt = j - i + 1;
        cnt = sq(cnt);
        ans -= cnt * (cnt - 1) * (cnt - 2) / 6ll;
        i = j;
    }

    ans += n * (n - 1) * (n - 2) / 6ll;

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}