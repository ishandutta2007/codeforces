#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< double, double > pdd;
typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m;

    cin >> n >> m;

    if(n > 30) {
        cout << m << "\n";
    }else {
        cout << m % (1 << n) << "\n";
    }

    return 0;
}