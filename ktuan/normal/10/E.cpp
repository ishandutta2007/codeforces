#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

int n;
long long a[404];
long long b[404];

void solve(long long z, long long *b) {
    Rep(j,n) if(z >= a[j]) {
        b[j] = z / a[j];
        z %= a[j];
    }
}

long long calc(long long z) {
    long long need = 0;
    Rep(j,n) if(z >= a[j]) {
        need += z / a[j];
        z %= a[j];
    }
    return need;
}

int main() {
    cin >> n;
    Rep(i,n) cin >> a[i];
    long long best = -1;
    Rep(i,n) {
        long long z = a[i] - 1;
        memset(b,0,sizeof(b));
        solve(z, b);
        long long need = 0;
        long long cur = 0;
        Rep(j,n) {
            need += b[j];
            cur += b[j] * a[j];
            if(calc(cur + a[j]) > need + 1) {
                if(best == -1 || best > cur + a[j]) best = cur + a[j];
            }
        }
    }
    cout << best << endl;
    return 0;   
}