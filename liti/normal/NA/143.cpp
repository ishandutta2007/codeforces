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

const int N = 100 + 10;
int a[N];

int main() {
    int q; 
    cin >> q; 

    while( q-- ) { 
        int n;
        cin >> n; 

        for(int i = 0; i < n; i++) 
            cin >> a[i]; 
        sort( a , a + n ); 
        int ans = 1; 
        for(int i = 1; i < n; i++) 
            if( a[i] - a[i-1] == 1 ) 
                ans = 2; 
        cout << ans << endl;
    }

    return 0;
}