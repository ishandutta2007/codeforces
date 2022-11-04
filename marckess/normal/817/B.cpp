#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
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
    
    int n, a[100005];
    ll can[100005];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);

    int act = a[0], j = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if ( a[i] == act )
            c++;
        else {
            can[j++] = c;
            c = 1;
            act = a[i];
        }
    }
    can[j++] = c;

    if ( can[0] == 3 || (j > 1 && can[0] + can[1] == 3) || (j > 2 && can[0] + can[1] + can[2] == 3) )
        cout << 1 << endl;
    else if ( j > 2 && can[0] + can[1] == 2 )
        cout << can[2] << endl;
    else if ( can[0] == 2 )
        cout << can[1] << endl;
    else if ( can[0] == 1 )
        cout << can[1] *  (can[1] - 1) / 2 << endl;
    else
        cout << can[0] * (can[0] - 1) * (can[0] - 2) / 6 << endl;


    return 0;
}