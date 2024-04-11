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

bool isPal ( string s ) {
    return s[0] == s[4] && s[1] == s[3];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s;

    cin >> s;

    int res = 0;
    while ( !isPal(s) ) {
        if ( s[4] == '9' ) {
            s[4] = '0';
            if ( s[3] == '5' ) {
                s[3] = '0';
                if ( s[0] == '2' && s[1] == '3' ) {
                    s[0] = '0'; s[1] = '0';
                } else if ( s[1] == '9' ) {
                    s[1] = '0';
                    s[0] += 1; 
                } else {
                    s[1] += 1;
                }
            } else {
                s[3] += 1;
            }
        } else {
            s[4] += 1;
        }
        res++;
    }

    cout << res << endl;

    return 0;
}