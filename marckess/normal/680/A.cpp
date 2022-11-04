#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int v[5], sum = 0, res;
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        sum += v[i];
    }

    res = sum;
    for (int i = 0; i < 5; i++) {
        int c = 0;
        for (int j = i; j < 5; j++)
            if ( v[j] == v[i] )
                c++;
        if ( c > 1 ) {
            res = min(res, sum - v[i] * min(3, c));
        }
    }

    cout << res << endl;

    return 0;
}