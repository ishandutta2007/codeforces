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
    int n;
    scanf("%d", &n);

    vec<int> cnt(n + 1);
    vec< pair<int, int> > a(n + 1);

    for(int i(1);i <= n;i++) {
        scanf("%d", &a[i].first);
        if(a[i].first > n) {
            puts("-1");
            return true;
        }
        cnt[a[i].first]++;
        a[i].second = i;
    }

    for(int i(1);i + 1 <= n;i++) {
        if(cnt[i] < cnt[i + 1]) {
            puts("-1");
            return true;
        }
    }

    sort(a.begin() + 1, a.end());

    vec<int> ans(n + 1);

    for(int i(1);i <= n;i++) {
        int j = i;
        while(j <= n && a[j].first == a[i].first) {
            ans[a[j].second] = j - i + 1;
            j++;
        }
        i = j - 1;
    }

    printf("%d\n", cnt[1]);

    for(int i(1);i <= n;i++) {
        printf("%d ", ans[i]);
    }

    puts("");

    return true;
}   

int main()  
{
    //while(solve());   
    solve();

    return 0;
}