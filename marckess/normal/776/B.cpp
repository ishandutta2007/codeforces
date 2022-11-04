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

#define M 100010
vi cr(M+5, 1);

void precal() {
    for(ll i = 2; i <= M; i++ )
        if ( cr[i] == 1 )
            for(ll j = i*i; j <= M; j+=i)
                cr[j] = 2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    precal();

    int k;
    cin >> k;
    if ( k > 2 )
        cout << 2 << endl;
    else
        cout << 1 << endl;

    for(int i = 2; i <= k + 1; i++ )
        cout << cr[i] << " ";
    cout << endl;

    return 0;
}