//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 1000 + 10;
int a[N];

int main() {
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    if(n % 2) {
        n--; 
        a[n] = 0;
    }

    ll ans = 0;

    for(int i = 0; i < n; i += 2) {
        ll sum = a[i];
        ll mn = a[i] - 1;
        for(int j = i + 1; j < n; j++) { 
            if( j % 2 == 0 ) {
                sum += a[j];
            } else { 
                if( sum - a[j] <= mn ) { 
                    ll lvl = max(0ll, sum - a[j]);
                    ans += mn - lvl + 1;
                }

                sum -= a[j];
                mn = min(mn, sum);
                if( sum < 0 ) 
                    break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}