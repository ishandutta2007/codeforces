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

int k;
string s;
vi v;

bool esPos (int m) {
    int col = 0, ancho = 0, i = 0;

    while ( i < v.size() ) {
        if ( col == k )
            return false;
        if ( ancho + v[i] > m ) {
            col ++;
            ancho = 0;
        } else {
            ancho += v[i];
            i++;
        }
    }
    return true;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> k;
    cin.ignore();
    getline(cin, s);

    int n = s.size();
    for ( int i = 0, c = 1; i <= n; i++, c++ ) {
        if ( i == n || s[i] == ' ' || s[i] == '-' ){
            v.push_back(c);
            c = 0;
        }
    }
    v.back() -= 1;

    int i = 0, j = n + 1, m = (i + j) / 2;
    for (int l = 0; l < 22; l++) {
        if ( esPos(m) )
            j = m;
        else
            i = m;
        m = (i + j) / 2;
    }

    cout << m + 1 << endl;

    return 0;
}