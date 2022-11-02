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

const int N = 10000 + 10;
int a[N];

void solve() { 
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i]; 

    bool handled = false; 

    if(a[0] == 1) {
        cout << n+1 << ' ';
        handled = true;
    }
    for(int i = 0; i < n; i++) {
        cout << i + 1 << ' ';
        if(!handled && i + 1 < n && a[i+1]) {
            cout << n+1 << ' ';
            handled = true; 
        }
    }
    if(!handled) 
        cout << n+1 << ' ';

    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    for(int i = 0 ;i < t; i++) 
        solve();
    return 0;
}