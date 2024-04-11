#include <bits/stdc++.h>

#include <unordered_set>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int n;
char s[N];

int main() {

    scanf("%d %s", &n, s);

    set< int > d, r;
    set< int > :: iterator fnd, qd, qr;

    for(int i = 0;i < n;i++) {
        if(s[i] == 'D') d.insert( i );
        else r.insert( i );
    }

    while(!d.empty() && !r.empty()) {
        for(int i = 0;i < n && !d.empty() && !r.empty();i++) {
            if(s[i] == 'D') {
                if(!d.count(i)) continue;
                fnd = r.lower_bound( i );
                if(fnd == r.end()) fnd = r.begin();
                r.erase( fnd );
            }else {
                if(!r.count(i)) continue;
                fnd = d.lower_bound( i );
                if(fnd == d.end()) fnd = d.begin();
                d.erase( fnd );
            }
        }
    }

    cout << (d.empty() ? "R" : "D") << "\n";

    return 0;
}