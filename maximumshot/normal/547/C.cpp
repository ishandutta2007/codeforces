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
#include <iomanip>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const double pi = acos(-1.0);

using namespace std;

const int NMAX = 5 * 100000 + 10;
bool prime[NMAX];
vec< int > f[NMAX];

void init() {
    for(int i = 0;i < NMAX;i++) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for(int i = 2;i * i < NMAX;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < NMAX;j += i) prime[j] = 0;
    }
    for(int i = 2;i < NMAX;i++) {
        if(!prime[i]) continue;
        for(int j = i;j < NMAX;j += i) f[j].push_back(i);
    }
}

LL ans = 0, cnt[NMAX];

LL get(int value, int k) {
    LL gg = 0;
    int sz = (int)f[value].size();
    for(int mask = 1;mask < (1 << sz);mask++) {
        int cntBit = 0, v = 1;
        for(int j = 0;j < sz;j++) {
            if((1 << j) & mask) {
                cntBit++;
                v *= f[value][j];
            }
        }
        if(k == 1) {
            if(cntBit % 2) gg += cnt[v];
            else gg -= cnt[v];
            cnt[v]++;
        }else {
            cnt[v]--;
            if(cntBit % 2) gg += cnt[v];
            else gg -= cnt[v];
        }
    }
    return gg;
}

bool solve()
{
    init();
    
    int n, q;
    scanf("%d %d", &n, &q);

    vec< int > a(n + 1);
    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);

    int x, value;

    vec< int > u(n + 1, 0);
    for(int i = 0;i < NMAX;i++) cnt[i] = 0;

    LL C = 0;

    while(q--) {
        scanf("%d", &x);
        
        if(u[x]) ans -= get(a[x], -1), C--;
        else ans += get(a[x], 1), C++;

        u[x] ^= 1;

        cout << C * (C - 1) / 2 - ans << '\n';
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}