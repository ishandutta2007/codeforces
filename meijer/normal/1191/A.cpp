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

int x, r;

int RANK[] = {3,0,2,1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>x;
    int mn=5, best=-1;
    REP(i,0,3) {
        r = (x+i)%4;
        if(RANK[r] < mn) {
            mn = RANK[r];
            best = i;
        }
    }
    char R = 'A' + mn;
    cout << best << " " << R << endl;
}