#include<bits/stdc++.h>
using namespace std;
int const nax = 5000 + 10 , mod = 1e9 + 7;

void plusle (int &a, int b) {
    ((a += b) >= mod ) ? a -= mod : a;
}

int mul (int a, int b) {
    return 1LL * a * b % mod ;
}

int power (int a, int b) {
    int res = 1 ;
    for ( ; b > 0 ; b >>= 1 , a = mul (a, a))
        if (b & 1) res = mul(res, a);
    return res;
}

int inv (int a) {
    return power(a,  mod - 2);
}


int n, m;
int s[nax];
vector<int> c[nax];
int tot_sleep, tot_way = 1 , way[nax], sl[nax], l[nax], r[nax], sleep, ans;

void upd (int nsleep, int ways) {
    if (nsleep > tot_sleep) {
        ans = ways;
        tot_sleep = nsleep ;
    }
    else if (nsleep == tot_sleep ) {
        plusle(ans , ways);
    }
}

void calc (int fav) {
    int a = upper_bound(c[fav].begin(), c[fav].end(), l[fav]) - c[fav].begin();
    int b = upper_bound(c[fav].begin(), c[fav].end(), r[fav]) - c[fav].begin();
    if (a < b)  swap(a, b);
    /// assume that left >= right
    int w = 1LL * (a - 1) * b % mod ;

    if (w > 0) {
        sl[fav] = 2;
        way[fav] = w;
    }
    else if (a > 0) {
        sl[fav] = 1;
        way[fav] = a + b;
    }
    else {
        sl[fav] = 0;
        way[fav] = 1;
    }
}

void cal_fix (int fav) {
    /// how many we can put in the right ?
    int x = upper_bound(c[fav].begin(), c[fav].end(), r[fav]) - c[fav].begin() ;
    if (r[fav] >= l[fav]) -- x; /// cut out fix cow
    if (x > 0) {
        sl[fav] = 2;
        way[fav] = x;
    }
    else sl[fav] = 1, way[fav] = 1;

}

int main () {
    /// note that each sweetness is independent
    scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", s + i);
        r[s[i]] ++ ;
        }
    for (int i = 1 ; i <= m ; ++ i) {
        int y, h;
        scanf("%d %d", &y, &h);
        c[y].emplace_back(h);
    }
    for (int i = 1 ; i <= n ; ++ i)
        sort(c[i].begin(), c[i].end() );

    for (int i = 1 ; i <= n ; ++ i) {
        calc(i);
        sleep += sl[i];
        tot_way = mul(tot_way , way[i]);
    }
    upd(sleep, tot_way);
    for (int i = 1 ; i <= n ; ++ i) {
        int fav = s[i];
        sleep -= sl[fav];
        tot_way = mul(tot_way, inv(way[fav]));
        l[fav] ++ ;
        r[fav] -- ;

        if (binary_search(c[fav].begin(), c[fav].end() , l[fav])) {
            cal_fix(fav);
            int cur_sleep = sleep + sl[fav] ;
            int cur_ways = mul(tot_way, way[fav]) ;
            upd(cur_sleep, cur_ways);
        }
        calc(fav);
        sleep += sl[fav] ;
        tot_way = mul(tot_way , way[fav]);
    }
    printf("%d %d\n", tot_sleep, ans);

}
/*
    Good Luck
        -Lucina
*/