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

const int N = -1;
const int mod = 1e9 + 7; 
int sum(int a, int b) { 
    int c = (a+b); 
    if( c >= mod) c-=mod; 
    return c; 
}
int mul(int a, int b) { 
    return 1ll*a*b % mod; 
}


void solve() { 
    int x; 
    cin >> x;
    string s; 
    cin  >> s; 

    int mx = 2 * x; 
    
    int len = sz(s); 
    for(int i = 1; i <= x; i++) { 
        int cur = i; 
        int rem = sum(len, mod - i); 

        len = sum(len, mul(rem , (s[i-1]-'1')));

        string t = ""; 
        if( sz(s) < mx && s[i-1] != '1' )
            t = s.substr( i , sz(s)  - i );
        while( sz(s) < mx && s[i-1] != '1' ) { 
            s += t;
            s[i-1]--;
        }
    } 

    cout << len << endl;
}

int main() {
    int t; 
    cin >> t; 
    while(t--)
        solve();
    return 0;
}