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

const int N = 1000*1000 + 100;

int last[N];
bool st[N];

void die() { 
    cout << -1 << endl;
    exit(0); 
}

int main() {
    int n; 
    cin >> n; 
    memset(last, -1, sizeof last); 

    int d = 0; 
    vector<int> ans; 
    int open = 0; 
    for(int i = 0; i < n; i++) { 
        int x; 
        cin >> x; 
        if( x < 0 ) { 
            x *= -1; 
            if( st[x] ) {
                open--; 
                st[x] = false; 
            } else
                die(); 
        } else { 
            if( last[x] >= d ) 
                die();

            last[x] = i; 
            st[x] = true;
            open++; 
        }

        if( open == 0 ) { 
            ans.pb( i - d + 1 ); 
            d = i+1; 
        }
    }

    if( open > 0 ) 
        die(); 

    cout << ans.size() << endl; 
    for(auto x : ans) 
        cout << x << ' '; 
    cout << endl;
    return 0;
}