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

const int N = 200*1000 + 100;

int a[N]; 
ll psum[N]; 

int main() {
    int n, m; 
    cin >> n >> m; 

    for(int i = 0; i < n; i++) 
        cin >> a[i]; 

    sort(a, a + n);
    ll ans = 0; 
    for(int i = 0; i < n; i++) { 
        if( i >= m ) 
            psum[i] = psum[i-m] + a[i];
        else
            psum[i] = a[i];

        ans += psum[i]; 

        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}