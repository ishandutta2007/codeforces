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

//#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const int inf = 1000000000ll;
const LL inf64 = 1ll * inf * inf;
const LL base = inf + 7;
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

bool solve() 
{
    int n, m;
    scanf("%d %d", &n, &m);

    if(m < n - 1) {
        puts("No");
        return true;
    }

    vec< pair<LL, LL> > a;

    for(int i(0);i < n;i++) {
        LL l, r;
        scanf("%I64d %I64d", &l, &r);
        a.push_back(mp(l, r));
    }

    set< pair<LL, int> > s;

    for(int i(1);i <= m;i++) {
        LL x;
        scanf("%I64d", &x);
        s.insert(mp(x, i));
    }
   
    vec< pair< pair<LL, LL>, int> > mas;
    
    vec< int > ans(n - 1);

    for(int i(0);i + 1 < n;i++) {
        LL l, r, A, B, C, D;
        A = a[i].first, B = a[i].second;
        C = a[i + 1].first, D = a[i + 1].second;
        l = C - B;
        r = D - A;
        mas.push_back(mp(mp(r, l), i));
    }
    
    sort(ALL(mas));

    for(int i(0);i < n - 1;i++) {
        LL l, r;
        int id;
        l = mas[i].first.second;
        r = mas[i].first.first;
        id = mas[i].second;
        set< pair<LL, int> >::iterator fnd = s.lower_bound(mp(l, -1));
        if(fnd == s.end()) {
            puts("No");
            return true;
        }
    
        if(r < fnd->first) {
            puts("No");
            return true;
        }

        ans[id] = fnd->second;

        s.erase(fnd);
    }
    
    puts("Yes");

    for(int i(0);i < n - 1;i++) printf("%d ", ans[i]);
    puts("");

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}