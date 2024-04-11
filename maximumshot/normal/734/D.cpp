#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int n;
vec< pair< pii, char > > a;
int X0, Y0;

void check1() {
    int yl, yr, xl, xr;
    char tyl, tyr;
    yl = -inf - 1;
    yr = inf + 1;
    for(int i = 0;i < n;i++) {
        if(a[i].first.first == X0) {
            if(a[i].first.second < Y0 && a[i].first.second > yl) {
                yl = a[i].first.second;
                tyl = a[i].second;
            }
            if(a[i].first.second > Y0 && a[i].first.second < yr) {
                yr = a[i].first.second;
                tyr = a[i].second;
            }
        }
    }
    if(yl != -inf - 1 && (tyl == 'R' || tyl == 'Q')) {
        puts("YES");
        exit(0);
    }
    if(yr != inf + 1 && (tyr == 'R' || tyr == 'Q')) {
        puts("YES");
        exit(0);
    }
    xl = -inf - 1;
    xr = inf + 1;
    for(int i = 0;i < n;i++) {
        if(a[i].first.second == Y0) {
            if(a[i].first.first < X0 && a[i].first.first > xl) {
                xl = a[i].first.first;
                tyl = a[i].second;
            }
            if(a[i].first.first > X0 && a[i].first.first < xr) {
                xr = a[i].first.first;
                tyr = a[i].second;
            }
        }
    }
    if(xl != -inf - 1 && (tyl == 'R' || tyl == 'Q')) {
        puts("YES");
        exit(0);
    }
    if(xr != inf + 1 && (tyr == 'R' || tyr == 'Q')) {
        puts("YES");
        exit(0);
    }
}

void check2() {
    int yl, yr;
    char tyl, tyr;
    yl = -inf - 1;
    yr = inf + 1;
    for(int i = 0;i < n;i++) {
        if(a[i].first.first + a[i].first.second == X0 + Y0) {
            if(a[i].first.second < Y0 && a[i].first.second > yl) {
                yl = a[i].first.second;
                tyl = a[i].second;
            }
            if(a[i].first.second > Y0 && a[i].first.second < yr) {
                yr = a[i].first.second;
                tyr = a[i].second;
            }
        }
    }
    if(yl != -inf - 1 && (tyl == 'B' || tyl == 'Q')) {
        puts("YES");
        exit(0);
    }
    if(yr != inf + 1 && (tyr == 'B' || tyr == 'Q')) {
        puts("YES");
        exit(0);
    }
    yl = -inf - 1;
    yr = inf + 1;
    for(int i = 0;i < n;i++) {
        if(a[i].first.first - a[i].first.second == X0 - Y0) {
            if(a[i].first.second < Y0 && a[i].first.second > yl) {
                yl = a[i].first.second;
                tyl = a[i].second;
            }
            if(a[i].first.second > Y0 && a[i].first.second < yr) {
                yr = a[i].first.second;
                tyr = a[i].second;
            }
        }
    }
    if(yl != -inf - 1 && (tyl == 'B' || tyl == 'Q')) {
        puts("YES");
        exit(0);
    }
    if(yr != inf + 1 && (tyr == 'B' || tyr == 'Q')) {
        puts("YES");
        exit(0);
    }
}

int main() {

//    cin >> n >> X0 >> Y0;
    scanf("%d %d %d", &n, &X0, &Y0);

    a.resize(n);

    for(int i = 0;i < n;i++) {
//        cin >> a[i].second >> a[i].first.first >> a[i].first.second;
        scanf(" %c %d %d", &a[i].second, &a[i].first.first, &a[i].first.second);
    }

    check1();
    check2();

    puts("NO");

    return 0;
}