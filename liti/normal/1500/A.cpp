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

const int N = 2*1000*100 + 100;
const int M = 6 * 1000 * 1000 + 100;

int a[N];

vector<pii> mp[M];

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < i; j++) {
            int sum = a[i] + a[j]; 
            for(auto p: mp[sum])
                if(p.F != j && p.S != j && p.S != i) {
                    cout << "YES\n" << 1+p.F << ' ' << 1+p.S << ' ' << i+1 << ' ' << j+1 << endl;
                    return 0;
                }
            mp[sum].pb( {j, i} );
        }
    }
    cout << "NO" << endl;

    return 0;
}