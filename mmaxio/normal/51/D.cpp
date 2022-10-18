#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

struct frac{
    int a, b;
    frac(int _a = 0, int _b = 0) {
        if (_a == 0 && _b == 0)
            a = 0, b = 1;
        else {
            int c = gcd(abs(_a), abs(_b));
            a = _a / c;
            b = _b / c;
            if (b < 0)
                b = -b,
                a = -a;
            if (b == 0 && a < 0)
                a = -a;
        }
    }
};

bool operator< (const frac x, const frac y) {
    if (x.a != y.a)
        return x.a < y.a;
    else
        return x.b < y.b;
}

bool operator!= (const frac x, const frac y) {
    return x.a != y.a || x.b != y.b;
}

bool operator== (const frac x, const frac y) {
    return x.a == y.a && x.b == y.b;
}

int x[100000];
frac f[100000];
int n;

bool pref[100000], suff[100000];

bool checkRemove() {
    if (suff[1] && f[n - 1] != frac(1, 0))
        return true;


    
    FORD(i, 1, n - 1)
        if ((i == 1 || pref[i - 2]) && (i == n - 1 || suff[i + 1])) {
            //cerr << i << ' ';
            frac tmp(x[i + 1], x[i - 1]);
            if ((i == 1 || tmp == f[0]) && (i == n - 1 || tmp == f[n - 1]))
                return true;
        }
    if (pref[n - 2] && f[0] != frac(1, 0))
        return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    scanf("%d",&n);
    if (n == 1) {
        puts("0");
        return 0;
    }

    REP(i, n) {
        scanf("%d",&x[i]);
    }

    if (n == 2) {
        if (x[0] == 0 && x[1] != 0) 
            puts("1");
        else
            puts("0");
        return 0;
    }


    n--;
    
    REP(i, n) f[i] = frac(x[i + 1], x[i]);

    //REP(i, n) cerr << f[i].a << '/' << f[i].b << '\n';

    pref[0] = true;
    FORD(i, 1, n - 1) pref[i] = pref[i - 1] && (f[i] == f[i - 1]);
    suff[n - 1] = true;
    FORP(i, n - 2, 0) suff[i] = suff[i + 1] && (f[i] == f[i + 1]);

    //REP(i, n) cerr << pref[i]; cerr << '\n';
    //REP(i, n) cerr << suff[i]; cerr << '\n';
    
    if (pref[n - 1] && f[0] != frac(1, 0)) {
        puts("0");
    } else if (checkRemove()) {
        puts("1");
    } else
        puts("2");
}