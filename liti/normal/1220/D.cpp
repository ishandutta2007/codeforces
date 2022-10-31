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

const int N = 200*1000 + 10;
const int L = 63;

ll a[N]; 

ll gcd(ll a, ll b)  { 
    return b ? gcd(b, a % b) : a;
}

vector<ll> ans[L];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 

    int n;
    cin >> n;

    int best = 0; 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int z = 0;
        ll x = a[i];
        for( ; x % 2 == 0; z++ )
            x /= 2;
        ans[z].pb(a[i]); 

        if( sz(ans[z]) > sz(ans[best]) )
            best = z; 
    }


    cout << n - sz(ans[best]) <<  endl;
    for(int i = 0; i < L; i++) 
        if( i != best ) 
            for(auto x : ans[i])
                cout << x << ' ' ;  
    cout << endl;
    return 0;
}