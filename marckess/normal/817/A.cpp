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
    
    int a,b,x1,x2,y1,y2;

    a=b=x1=x2=y1=y2=1;

    for (int i = 0; i < 1e7; i++) {
    	a = a * x2 / x1;
    }

    cin >> x1 >> y1 >> x2 >> y2 >> a >> b;

    if ( abs(x1-x2) % a == 0 && abs(y1-y2) % b == 0 &&
        (abs(x1-x2) / a) % 2 == (abs(y1-y2) / b) % 2 )
        cout << "YES";
    else
        cout << "NO";

    return 0;
}