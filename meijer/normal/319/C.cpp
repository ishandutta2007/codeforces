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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef complex<double> vec;
#define X real()
#define Y imag()
#define INF 1e9
#define EPS 1e-9
#define PI 2*acos(0)
#define REP(i, a, b) for(int i = int(a); i != int(b); i++)

const int N = 2e5;

int n;
ll a[N], b[N];
ll mem[N];
int q[N];
int L, R;

ll m(int k, int j) {
    return mem[j] - mem[k];
}
ll l(int k, int j) {
    return a[k] - a[j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    REP(i,0,n) cin >> a[i];
    REP(i,0,n) cin >> b[i];

    L = R = 0;
    mem[n-1] = 0;
    q[R++] = n-1;
    for(int i=n-2; i!=-1; i--) {
        while(R-L >= 2 && m(q[L], q[L+1]) < b[i]*l(q[L], q[L+1]))
            L++;
        mem[i] = mem[q[L]] + a[q[L]]*b[i];
        while(R-L >= 2 && m(q[R-2], q[R-1])/l(q[R-2], q[R-1]) > m(q[R-1], i)/l(q[R-1], i))
            R--;
        q[R++] = i;
    }

    cout << mem[0] << endl;
}