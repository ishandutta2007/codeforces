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

int cnt[5], sum[5][5]; 
int a[5];

void solve() {
    memset(sum, 0, sizeof sum); 
    memset(cnt, 0, sizeof cnt); 

    int n; 
    cin >> n; 

    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < 5; j++) { 
            cin >> a[j]; 
            cnt[j] += a[j]; 

            if(a[j]) 
                for(int k = 0; k < j; k++) 
                    if(a[k])
                        sum[k][j]++;
        }
    }

    for(int i = 0; i < 5; i++) 
        for(int j = 0; j < i; j++) { 
            int left = cnt[j] - sum[j][i], right = cnt[i] - sum[j][i]; 
            if (left <= n/2 && right <= n/2 && left + right + sum[j][i] == n) {
                cout << "YES\n";
                return;
            }
        }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}