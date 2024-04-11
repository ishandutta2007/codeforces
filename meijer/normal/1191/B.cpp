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

string a, b, c;

int getMinKoutsu() {
    if(a == b && b == c) return 0;
    if(a == b || b == c || a == c) return 1;
    return 2;
}
int getMinShuntsu(int n1, int n2, int n3) {
    if(abs(n1 - n2) == 1 && abs(n2 - n3) == 1 && abs(n1 - n3) == 2) return 0;
    if(abs(n1 - n3) == 1 && abs(n3 - n2) == 1 && abs(n1 - n2) == 2) return 0;
    if(abs(n2 - n1) == 1 && abs(n1 - n3) == 1 && abs(n2 - n3) == 2) return 0;
    if(abs(n1 - n3) == 1 || abs(n2 - n1) == 1 || abs(n2 - n3) == 1) return 1;
    if(abs(n1 - n3) == 2 || abs(n2 - n1) == 2 || abs(n2 - n3) == 2) return 1;
    return 2;
}
int getMinShuntsu() {
    if(a[1] == b[1] && b[1] == c[1])
        return getMinShuntsu(a[0], b[0], c[0]);
    if(a[1] == b[1])
        return getMinShuntsu(a[0], b[0], INF);
    if(c[1] == b[1])
        return getMinShuntsu(c[0], b[0], INF);
    if(a[1] == c[1])
        return getMinShuntsu(a[0], c[0], INF);
    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b>>c;
    cout << min(getMinShuntsu(), getMinKoutsu()) << endl;
}