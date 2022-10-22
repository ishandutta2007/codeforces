#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef complex<double> vec;
#define X real()
#define Y imag()
#define INF 1e18
#define EPS 1e-9
#define PI 2*acos(0)
#define REP(i, a, b) for(int i = int(a); i != int(b); i++)

const int N = 300000;
int n, K;
ld sum[N];
ld f[N];
ld c[N];
int t[N];
ld mem[N][60];
ld memk[N];
int memC[N];
int q[N];
int L, R;

ld y(int j) {
    return memk[j] - c[j] + f[j]*sum[j];
}
ld m(int k, int j) {
    return y(j) - y(k);
}
ld l(int k, int j) {
    return sum[j] - sum[k];
}
ld getCost(int L, int R) {
    return c[R] - c[L] - (f[R]-f[L])*double(sum[L]);
}
void fillMem(double C) {
    L = R = 0;
    memk[0] = 0;
    memC[0] = 0;
    q[R++] = 0;
    REP(i,1,n+1) {
        while(R-L >= 2 && m(q[L], q[L+1]) < f[i]*l(q[L], q[L+1]))
            L++;
        memk[i] = memk[q[L]] + getCost(q[L], i) + C, memC[i] = memC[q[L]] + 1;
        while(R-L >= 2 && m(q[R-2],q[R-1])*l(q[R-1], i) > l(q[R-2],q[R-1])*m(q[R-1], i))
            R--;
        q[R++] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> K;
    REP(i,1,n+1) cin>>t[i];

    //preprocessing
    t[0] = sum[0] = f[0] = c[0] = 0;
    REP(i,1,n+1) sum[i] = sum[i-1] + ld(t[i]);
    REP(i,1,n+1) f[i]   = f[i-1] + 1.0/ld(t[i]);
    REP(i,1,n+1) c[i]   = c[i-1] + sum[i]/ld(t[i]);

    ld lb=0.0, ub=c[n];
    while(ub-lb > 1e-3) {
        ld mid = (ub+lb)/2.0;
        fillMem(mid);
        if(memC[n] <= K) ub = mid;
        else lb = mid;
    }
    fillMem(ub);

    printf("%.10f\n", double(memk[n] - ld(K*ub)));
}