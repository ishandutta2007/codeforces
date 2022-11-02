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

const int N = 3000*100 + 10;
int  a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 

    int n; 
    cin >> n;

    ll x = 0, y = 0; 
    for(int i = 0; i < n; i++) { 
        cin >> a[i]; 
        if( i % 2 ) {
            x += a[i]/2;
            y += a[i] - a[i]/2;
        } else { 
            y += a[i]/2;
            x += a[i] - a[i]/2;
        }
    }

    cout << min(x,y) << endl;
    return 0;
}