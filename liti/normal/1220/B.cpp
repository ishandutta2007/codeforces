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

int a[N][N]; 

int sq(ll v) { 
    ll x = sqrt(v); 
    for(ll y = max(0ll,x - 20); ; y++) 
        if( y * y == v ) 
            return y;
}

int main() {
    int n;
    cin >> n; 

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            cin >> a[i][j]; 

    for(int i = 0; i < n; i++) { 
        int j = (i+1) % n; 
        int k = (j+1) % n; 

        cout << sq(1ll * a[i][j] * 1ll * a[i][k] / a[j][k]) << ' ';
    }

    return 0;
}