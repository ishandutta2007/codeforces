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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k, a[105], b[105];

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < k; i++)
        cin >> b[i];

    sort (b, b + k, greater<int>());

    bool res = false;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if ( a[i] == 0 )
            a[i] = b[j++];
        if ( i && a[i] < a[i-1] )
            res = true;
    }

    if (res)
        cout << "Yes";
    else
        cout << "No";
cout << endl;

    return 0;
}