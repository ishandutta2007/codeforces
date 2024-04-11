#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {
    
    int m, d;
    
    cin >> m >> d;
    
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int first = 7 - d + 1;
    int tot = a[m] - first;
    
    tot = (tot + 6) / 7;
    
    cout << tot + 1 << "\n";
    
    return 0;
}