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

void solve() {
    int n;
    cin >> n; 
    string s;
    cin >> s; 

    for(auto& x: s) 
        if (x == 'U') 
            x = 'D';
        else if(x == 'D')
            x = 'U';
    cout << s << '\n';

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}