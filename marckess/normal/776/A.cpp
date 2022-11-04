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
    string a, b, s1, s2;
    int n;
    cin >> s1 >> s2 >> n;
    cout << s1 << " " << s2 << endl;
    while(n--) {
        cin >> a >> b;
        if ( a == s1 )
            s1 = b;
        else
            s2 = b;
        cout << s1 << " " << s2 << endl;
    }

    return 0;
}