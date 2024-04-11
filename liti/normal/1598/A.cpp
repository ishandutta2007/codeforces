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

string a[2];
void solve() {
    int n;
    cin >> n;
    cin >> a[0] >> a[1]; 
    bool good = true; 
    for(int i = 0; i < n; i++) 
        good &= (a[0][i] == '0' || a[1][i] == '0');
    cout << (good? "YES": "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}