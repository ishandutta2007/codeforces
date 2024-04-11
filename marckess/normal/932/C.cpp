#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, a, b;
int res[1000005];


void obtRes (int x, int y) {
    for (int i = 1; i <= n;) {
        if (x) {
            res[i+a-1] = i;
            for (int j = 1; j < a; j++, i++)
                res[i] = i+1;
            i++;
            x--;
        } else if (y) {
            res[i+b-1] = i;
            for (int j = 1; j < b; j++, i++)
                res[i] = i+1;
            i++;
            y--;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> a >> b;
    for (int i = 0; i*a <= n; i++) {
        int d = n-i*a;
        if (d % b == 0) {
            obtRes(i, d/b);
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}