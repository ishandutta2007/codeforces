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

const int N = 100 * 1000 + 100;

int a[N], b[N]; 
int diff[N]; 

int main() {
    int t; 
    cin >> t; 
    while( t-- ) { 
        int n;
        cin >> n; 

        for(int i = 0; i < n; i++) 
            cin >> a[i];

        bool canDo = true;
        int l = -1, r = -1; 
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            diff[i] = b[i] - a[i]; 

            if( diff[i] < 0 ) canDo = false; 
            if( diff[i] > 0 ) { 
                if( l == -1 ) l = i; 
                r = i; 
            }
        }

        if( canDo && *min_element(diff + l, diff + r + 1) == *max_element(diff + l, diff + r +  1)) { 
            cout << "YES\n";
        } else  {  
            cout << "NO\n";
        }
    }
    return 0;
}