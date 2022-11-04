#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 1000005;

int ft[MX];

void update (int i) {
    while (i < MX) {
        ft[i]++;
        i += i & -i;
    }
}

int query (int i) {
    int sum = 0;
    while (i) {
        sum += ft[i];
        i -= i & -i;
    }
    return sum;
}

int n, a[MX];
ll sum = 0;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; i >= 0; i--) {
        sum += query(a[i]);
        update(a[i]);
    }

    if ((sum % 2) ^ (n % 2))
        cout << "Um_nik" << endl;
    else
        cout << "Petr" << endl;

    return 0;
}