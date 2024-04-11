#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

double const pi = acos(-1.0);
double const eps = 1e-10;

bool solve() {

    int n, m;

    cin >> n >> m;

    vec< string > a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    vec< vec< int > > k(n, vec< int >(m));
    vec< vec< int > > f = k;

    int res = 0;

    for(int i = n - 1;i >= 0;i--) {
        for(int j = m - 1;j >= 0;j--) {
            for(int I = i;I >= 0;I = (I & (I + 1)) - 1)
                for(int J = j;J >= 0;J = (J & (J + 1)) - 1)
                    k[i][j] += f[I][J];
            int add;
            if(a[i][j] == 'W') {
                add = 1 - k[i][j];
            }else {
                add = -1 - k[i][j];
            }
            if(add != 0) res++;
            for(int I = 0;I < n;I |= (I + 1))
                for(int J = 0;J < m;J |= (J + 1))
                    f[I][J] += add;
            for(int I = 0;I < n;I |= (I + 1))
                for(int J = j + 1;J < m;J |= (J + 1))
                    f[I][J] -= add;
            for(int I = i + 1;I < n;I |= (I + 1))
                for(int J = 0;J < m;J |= (J + 1))
                    f[I][J] -= add;
            for(int I = i + 1;I < n;I |= (I + 1))
                for(int J = j + 1;J < m;J |= (J + 1))
                    f[I][J] += add;
        }
    }

    cout << res << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}