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

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) { 
        int n; 
        cin >> n; 
        int ans = (1<<30)-1;
        for(int j = 0; j < n; j++) { 
            int x;
            cin >> x;
            ans &= x;
        }
        cout << ans << '\n';
    }
    return 0;
}