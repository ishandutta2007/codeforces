#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

const int MAXB = 128;
double vx[MAXB], prob[MAXB];

int n, x;

vector< vector<double> > m;

vector< vector<double> > mul(const vector< vector<double> >& a, const vector< vector<double> >& b) {
    vector< vector<double> > res(MAXB, vector<double>(MAXB, 0.0));

    FORN(i, MAXB) FORN(j, MAXB) FORN(k, MAXB) {
        res[i][j] += a[i][k] * b[k][j];
    }

    return res;
}

vector< vector<double> > pow(vector< vector<double> > a, LL b) {
    vector< vector<double> > res(MAXB, vector<double>(MAXB, 0.0));
    FORN(i, MAXB) res[i][i] = 1.0;

    for (; b; b >>= 1) {
        if (b & 1) {
            res = mul(res, a); 
        }
        a = mul(a, a);
    }

    return res;
}

int main() {
    cin >> n >> x;

    FORN(i, x+1) {
        cin >> vx[i];
        prob[i] = 0.0;
    }

    m.resize(MAXB, vector<double>(MAXB, 0.0));

    FORN(i, MAXB) FORN(j, x+1) {
        int ni = i ^ j;
        m[i][ni] += vx[j];
    }

//    FORN(i, 4) { FORN(j, 4) cout << m[i][j] << " "; cout << "\n"; }

    m = pow(m, n-1);

    FORN(i, MAXB) FORN(j, MAXB) {
        prob[i] += m[i][j] * vx[j];
    }

    cout << setprecision(12) << 1.0 - prob[0] << "\n";

    return 0;
}