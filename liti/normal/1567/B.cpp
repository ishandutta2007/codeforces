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

const int N = 3*1000*100 + 100;
int psum[N];

void solve() {
    int a, b;
    cin >> a >> b; 

    int sum = psum[a]; 

    int ans;
    if (sum == b) 
        ans = a;
    else if((sum ^ b) != a) 
        ans = a + 1; 
    else
        ans = a + 2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    for(int i = 1; i < N; i++)
        psum[i] = psum[i-1] ^ (i-1); 

    int t;
    cin >> t;
    while(t--) 
        solve();
    return 0;
}