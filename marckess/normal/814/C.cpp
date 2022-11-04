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

vector<vi> v(27);
vector<vi> res(27, vi(1505, -1));
int n, q;
string s;

void getV () {
    for (int i = 0; s[i]; i++)
        v[s[i]-'a'].push_back(i);
}

int getRes (int a, int c) {
    if ( res[c][a] > -1 )
        return res[c][a];

    int rec = a, tam = 0, i = -1, j = 0, mx = a;

    for ( j; j < v[c].size(); j++) {
        rec -= v[c][j] - ( j ? v[c][j-1] : -1 ) - 1;
        do {
            while ( rec < 0 ){
                i++;
                if ( i ) {
                    rec += v[c][i] - v[c][i-1] - 1;
                } else {
                    rec += v[c][i];
                }
            }
            tam = v[c][j] - ( i > -1 ? v[c][i] : 0 ) + 1;
        } while ( rec < 0 );

        mx = max (mx, tam + rec);
    }

    return res[c][a] = min (mx, n);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    char c;
    int a;

    cin >> n >> s >> q;

    getV();

    while ( q-- ) {
        cin >> a >> c;
        cout << getRes(a, c - 'a') << endl;
    }

}