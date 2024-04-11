#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

const int MN = 1e5+5;
int n;
vi z(MN), res, acu(MN);
string s;

void obtZ () {
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r-i+1, z[i-l]);
        
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        
        if (i+z[i]-1 > r)
            l = i, r = i+z[i]-1;
    }
    z[0] = n;
}

int main () {   
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> s;
    n = s.size();

    obtZ();

    for (int i = n - 1; i >= 0; i--) {
        if (i + z[i] == n)
            res.push_back(z[i]);
        acu[z[i]]++;
    }

    for (int i = n; i >= 0; i--)
        acu[i] += acu[i+1];

    cout << res.size() << endl;
    for (int x : res) {
        cout << x << " " << acu[x] << endl;
    }

    return 0;
}