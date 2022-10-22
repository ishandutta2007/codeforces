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
#include <list>
#include <cstring>

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

const int NMAX = 100000;

int c[NMAX];
bool prime[NMAX];
LL cnt[5][10][10][10][10];

vec< int > gen(int x) {
    vec< int > ans;
    while(x) ans.push_back(x % 10), x /= 10;
    reverse(ALL(ans));
    return ans;
}

LL sol2(int x) {
    vec< int > a = gen(x);
    LL ans = 0;
    for(int i = 0;i < 10;i++) {
        int value = a[1] * 10 + i;
        ans += prime[value];
    }
    return ans;
}

LL sol3(int x) {
    vec< int > a = gen(x);
    LL ans = 0;
    for(int k1 = 0;k1 < 10;k1++) {
        for(int k2 = 0;k2 < 10;k2++) {
            for(int k3 = 0;k3 < 10;k3++) {
                int value1, value2;
                value1 = a[1] * 100 + k1 * 10 + k2;
                value2 = a[2] * 100 + k2 * 10 + k3;
                if(prime[value1] && prime[value2]) ans++;
            }
        }
    }
    return ans;
}

LL sol4(int x) {
    vec< int > a = gen(x);
    LL ans = 0;
    for(int k1 = 0;k1 < 10;k1++) {
        for(int k2 = 0;k2 < 10;k2++) {
            for(int k3 = 0;k3 < 10;k3++) {
                for(int k4 = 0;k4 < 10;k4++) {
                    for(int k5 = 0;k5 < 10;k5++) {
                        for(int k6 = 0;k6 < 10;k6++) {
                            int value1, value2, value3;
                            value1 = a[1] * 1000 + k1 * 100 + k2 * 10 + k3;
                            value2 = a[2] * 1000 + k2 * 100 + k4 * 10 + k5;
                            value3 = a[3] * 1000 + k3 * 100 + k5 * 10 + k6;
                            if(prime[value1] && prime[value2] && prime[value3]) ans++;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

LL sol5(int x) {
    vec< int > a = gen(x);
    LL ans = 0;
    for(int k1 = 0;k1 < 10;k1++) {
        for(int k2 = 0;k2 < 10;k2++) {
            for(int k3 = 0;k3 < 10;k3++) {
                for(int k4 = 0;k4 < 10;k4++) {
                    for(int k5 = 0;k5 < 10;k5++) {
                        for(int k6 = 0;k6 < 10;k6++) {
                            LL c1, c2, c3, c4;
                            c1 = cnt[1][a[1]][k1][k2][k3];
                            c2 = cnt[2][a[2]][k1][k4][k5];
                            c3 = cnt[3][a[3]][k2][k4][k6];
                            c4 = cnt[4][a[4]][k3][k5][k6];
                            ans += c1 * c2 * c3 * c4;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

bool solve()
{       
    for(int x, i = 1;i < NMAX;i++) {
        c[i] = 0;
        x = i;
        while(x) c[i]++, x /= 10;
        prime[i] = 1;
    }

    prime[0] = prime[1] = 0;

    for(int i = 2;i * i < NMAX;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < NMAX;j += i) prime[j] = 0;
    }

    for(int k1 = 0;k1 < 5;k1++) {
        for(int k2 = 0;k2 < 10;k2++ ){
            for(int k3 = 0;k3 < 10;k3++) {
                for(int k4 = 0;k4 < 10;k4++) {
                    for(int k5 = 0;k5 < 10;k5++) {
                        cnt[k1][k2][k3][k4][k5] = 0;
                    }
                }
            }
        }
    }

    for(int i = 0;i < NMAX;i++) {
        if(!prime[i]) continue;

        vec< int > a = gen(i);

        reverse(ALL(a));
        while((int)a.size() < 5) a.push_back(0);
        reverse(ALL(a));

        int k1, k2, k3, k4;
        
        // 1
        k1 = a[0], k2 = a[2], k3 = a[3], k4 = a[4];
        cnt[1][k1][k2][k3][k4]++;
        // 2
        k1 = a[0], k2 = a[1], k3 = a[3], k4 = a[4];
        cnt[2][k1][k2][k3][k4]++;
        // 3
        k1 = a[0], k2 = a[1], k3 = a[2], k4 = a[4];
        cnt[3][k1][k2][k3][k4]++;
        // 4
        k1 = a[0], k2 = a[1], k3 = a[2], k4 = a[3];
        cnt[4][k1][k2][k3][k4]++;
    }


    int t, value;
    LL A;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &value);
        if(c[value] == 2) A = sol2(value);
        else if(c[value] == 3) A = sol3(value);
        else if(c[value] == 4) A = sol4(value);
        else A = sol5(value);
        printf("%I64d\n", A);
    }

    return true;
}  

int main() 
{
    //while(solve());
    solve();
    
    return 0;
}