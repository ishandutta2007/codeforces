#include <iostream>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef complex<double> vec;
#define X real()
#define Y imag()
#define INF 1e9
#define EPS 1e-9
#define PI 2*acos(0)
#define REP(i, a, b) for(int i = int(a); i != int(b); i++)

ll n, m, k, temp, p[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    REP(i,0,m) cin>>temp, p[i] = temp;
    sort(p,p+m);
    ll ans = 0, L = 0;
    while(true) {
        if(L == m) break;;
        ll page = (p[L] - L - 1)/k;
        ll i = L;
        while(i != m && (p[i] - L - 1)/k == page) i++;
        ans++;
        L = i;
    }
    cout<<ans<<endl;
}